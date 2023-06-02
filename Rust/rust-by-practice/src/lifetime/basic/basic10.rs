/* Remove all the lifetimes that can be elided */

fn input(x: &i32) {
    println!("`annotated_input`: {}", x);
}

fn pass(x: &i32) -> &i32 {
    x
}

fn longest<'a, 'b>(x: &'a str, y: &'b str) -> &'a str {
    x
}

struct Owner(i32);

impl Owner {
    // Annotate lifetimes as in a standalone function.
    fn add_one(&mut self) {
        self.0 += 1;
    }
    fn print(&self) {
        println!("`print`: {}", self.0);
    }
}

struct Person {
    age: u8,
    name: &'static str,
}

enum Either<'a> {
    Num(i32),
    Ref(&'a i32),
}

fn main() {}
