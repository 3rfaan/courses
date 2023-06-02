// Fix the error without removing code line
fn main() {
    let s = String::from("hello, world");

    print_str(&s); // or: print_str(s.clone());

    println!("{}", s);
}

fn print_str(s: &String) {
    // or fn print_str(s: &str)
    println!("{}", s)
}
