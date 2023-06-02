// Use two approaches to fix the error and without adding a new line
fn main() {
    let s = "hello, world".to_string(); // or: remove `to_string()` method
    let s1: &str = &s;

    println!("Success!");
}
