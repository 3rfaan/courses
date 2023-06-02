// Fix errors without removing any line
fn main() {
    let s1 = String::from("hello,");
    let s2 = String::from("world!");
    let s3 = s1.clone() + s2.as_str(); // or: let s3 = s1.clone() + &s2;
    assert_eq!(s3, "hello,world!");
    println!("{}", s1);
}
