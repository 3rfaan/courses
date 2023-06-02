fn main() {
    let s = give_ownership();
    println!("{}", s);
}

// Only modify the code below!
fn give_ownership() -> String {
    let s = String::from("hello, world");
    // Convert String to Vec
    let _s: &[u8] = s.as_bytes();
    s
}
