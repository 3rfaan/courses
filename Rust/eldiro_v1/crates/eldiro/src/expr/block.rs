use crate::env::Env;
use crate::stmt::Stmt;
use crate::utils;
use crate::val::Val;

#[derive(Clone, Debug, PartialEq)]
pub(crate) struct Block {
    pub(crate) stmts: Vec<Stmt>,
}

impl Block {
    pub(super) fn new(s: &str) -> Result<(&str, Self), String> {
        let s = utils::tag("{", s)?;
        let (s, _) = utils::extract_whitespace(s);

        let (s, stmts) = utils::sequence(Stmt::new, utils::extract_whitespace, s)?;

        let (s, _) = utils::extract_whitespace(s);
        let s = utils::tag("}", s)?;

        Ok((s, Block { stmts }))
    }

    pub(super) fn eval(&self, env: &Env) -> Result<Val, String> {
        if self.stmts.is_empty() {
            return Ok(Val::Unit);
        }

        let mut env = env.create_child();

        let stmts_except_last = &self.stmts[..self.stmts.len() - 1];
        for stmt in stmts_except_last {
            stmt.eval(&mut env)?;
        }

        self.stmts.last().unwrap().eval(&mut env)
    }
}

#[cfg(test)]
mod tests {
    use super::super::{BindingUsage, Expr, Number, Op};
    use super::*;
    use crate::binding_def::BindingDef;

    #[test]
    fn parse_empty_block() {
        assert_eq!(Block::new("{}"), Ok(("", Block { stmts: Vec::new() })));
    }

    #[test]
    fn parse_empty_block_with_whitespace() {
        assert_eq!(Block::new("{   }"), Ok(("", Block { stmts: Vec::new() })));
    }

    #[test]
    fn parse_block_with_one_stmt() {
        assert_eq!(
            Block::new("{ 5 }"),
            Ok((
                "",
                Block {
                    stmts: vec![Stmt::Expr(Expr::Number(Number(5)))]
                }
            ))
        );
    }

    #[test]
    fn parse_block_with_multiple_stmts() {
        assert_eq!(
            Block::new(
                "{
    let a = 10
    let b = a
    b
}",
            ),
            Ok((
                "",
                Block {
                    stmts: vec![
                        Stmt::BindingDef(BindingDef {
                            name: "a".to_string(),
                            val: Expr::Number(Number(10)),
                        }),
                        Stmt::BindingDef(BindingDef {
                            name: "b".to_string(),
                            val: Expr::BindingUsage(BindingUsage {
                                name: "a".to_string(),
                            }),
                        }),
                        Stmt::Expr(Expr::BindingUsage(BindingUsage {
                            name: "b".to_string(),
                        })),
                    ],
                },
            )),
        );
    }

    #[test]
    fn eval_empty_block() {
        assert_eq!(
            Block { stmts: Vec::new() }.eval(&Env::default()),
            Ok(Val::Unit)
        );
    }

    #[test]
    fn eval_block_with_one_expr() {
        assert_eq!(
            Block {
                stmts: vec![Stmt::Expr(Expr::Number(Number(25)))]
            }
            .eval(&Env::default()),
            Ok(Val::Number(25))
        );
    }

    #[test]
    fn eval_block_with_binding_def_and_usage() {
        assert_eq!(
            Block {
                stmts: vec![
                    Stmt::BindingDef(BindingDef {
                        name: "one".to_string(),
                        val: Expr::Number(Number(1))
                    }),
                    Stmt::Expr(Expr::BindingUsage(BindingUsage {
                        name: "one".to_string()
                    }))
                ]
            }
            .eval(&Env::default()),
            Ok(Val::Number(1))
        );
    }

    #[test]
    fn eval_block_with_multiple_binding_defs() {
        assert_eq!(
            Block {
                stmts: vec![
                    Stmt::BindingDef(BindingDef {
                        name: "foo".to_string(),
                        val: Expr::Number(Number(5))
                    }),
                    Stmt::BindingDef(BindingDef {
                        name: "bar".to_string(),
                        val: Expr::Number(Number(4))
                    }),
                    Stmt::BindingDef(BindingDef {
                        name: "baz".to_string(),
                        val: Expr::Number(Number(3))
                    })
                ]
            }
            .eval(&Env::default()),
            Ok(Val::Unit)
        );
    }

    #[test]
    fn eval_block_with_multiple_exprs() {
        assert_eq!(
            Block {
                stmts: vec![
                    Stmt::Expr(Expr::Number(Number(100))),
                    Stmt::Expr(Expr::Number(Number(30))),
                    Stmt::Expr(Expr::Operation {
                        lhs: Box::new(Expr::Number(Number(10))),
                        rhs: Box::new(Expr::Number(Number(7))),
                        op: Op::Sub
                    })
                ]
            }
            .eval(&Env::default()),
            Ok(Val::Number(3))
        );
    }

    #[test]
    fn eval_block_using_bindings_from_parent_env() {
        let mut env = Env::default();
        env.store_binding("foo".to_string(), Val::Number(2));

        assert_eq!(
            Block {
                stmts: vec![
                    Stmt::BindingDef(BindingDef {
                        name: "baz".to_string(),
                        val: Expr::BindingUsage(BindingUsage {
                            name: "foo".to_string()
                        })
                    }),
                    Stmt::Expr(Expr::BindingUsage(BindingUsage {
                        name: "baz".to_string()
                    }))
                ]
            }
            .eval(&env),
            Ok(Val::Number(2))
        );
    }
}
