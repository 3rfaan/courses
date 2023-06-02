// FILL in the blanks
fn main() {
    let mut s = String::new();
    s.push_str("hello");

    // Some bytes, in a vector
    let v: Vec<u8> = vec![104, 101, 108, 108, 111];

    // Turn a byte's vector into a String
    let s1: String = String::from_utf8(v).unwrap();

    assert_eq!(s, s1);

    println!("Success!");
}
