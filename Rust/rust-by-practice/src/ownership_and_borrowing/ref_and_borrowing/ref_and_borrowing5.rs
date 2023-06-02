fn main() {
    let mut s = String::from("hello, ");

    // Fill the blank to make it work
    let p = &mut s;

    p.push_str("world");

    println!("Success!");
}
