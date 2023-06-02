// From is now included in `std::prelude`, so there is no need to introduce it into the current scope
// use std::convert::From;

#[derive(Debug)]
struct Number {
    value: i32,
}

impl From<i32> for Number {
    fn from(n: i32) -> Number {
        Number { value: n }
    }
}

// FILL in the blanks
fn main() {
    let num = Number::from(30);
    assert_eq!(num.value, 30);

    let num: Number = 30_i32.into();
    assert_eq!(num.value, 30);

    println!("Success!");
}
