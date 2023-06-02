// FILL in the blanks and FIX errors
// 1. Don't use `to_string()`
// 2. Don't add/remove any code line
fn main() {
    let mut s: String = String::from("hello, ");
    s.push_str("world");
    s.push('!');

    move_ownership(s.clone());

    assert_eq!(s, "hello, world!");

    println!("Success!");
}

fn move_ownership(s: String) {
    println!("ownership of \"{}\" is moved here!", s)
}
