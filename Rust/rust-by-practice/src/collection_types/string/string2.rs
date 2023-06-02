// FILL in the blanks
fn main() {
    let s = String::from("hello, world");

    let slice1: &str = &s; // or: let slice1: &str = s.as_str()
    assert_eq!(slice1, "hello, world");

    let slice2 = &s[..5];
    assert_eq!(slice2, "hello");

    let mut slice3: String = s.to_string(); // or: s.to_owned()
    slice3.push('!');
    assert_eq!(slice3, "hello, world!");

    println!("Success!");
}
