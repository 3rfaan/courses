#[derive(Debug)]
struct NoCopyType {}

#[derive(Debug)]
#[allow(dead_code)]
struct Example<'a, 'b> {
    a: &'a u32,
    b: &'b NoCopyType,
}

/* Fix function signature */
fn fix_me<'a>(foo: &'a Example) -> &'a NoCopyType {
    foo.b
}

fn main() {
    let no_copy = NoCopyType {};
    let example = Example { a: &1, b: &no_copy };
    fix_me(&example);
    println!("Success!")
}
