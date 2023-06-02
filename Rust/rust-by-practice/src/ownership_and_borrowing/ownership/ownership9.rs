fn main() {
    let t = (String::from("hello"), String::from("world"));

    // Fill the blanks
    let (s1, s2) = &t; // or: let (s1, s2) = t.clone();

    println!("{:?}, {:?}, {:?}", s1, s2, t); // -> "hello", "world", ("hello", "world")
}
