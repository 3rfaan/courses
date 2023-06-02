// Fix error with at least two solutions
fn main() {
    let s = "hello, world".to_string(); // or: let s = "hello, world".to_owned();, or: let s =
                                        // String::from("hello, world");
    greetings(s)
}

fn greetings(s: String) {
    println!("{}", s)
}
