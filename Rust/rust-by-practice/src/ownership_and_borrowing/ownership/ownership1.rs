fn main() {
    // Use as many approaches as you can to make it work
    let x = String::from("hello, world");
    let y = x.clone();
    println!("{},{}", x, y);
}

// Other solutions:
//
// let x = "hello, world";
// let y = x;
//
// let x = String::from("hello, world");
// let y = &x[..];
//
// let x = &String::from("hello, world");
// let y = x;
//
// let x = String::from("hello, world");
// let y = x.as_str();
