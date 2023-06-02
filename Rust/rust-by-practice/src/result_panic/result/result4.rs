use std::num::ParseIntError;

// FILL in the blank in two ways: map, and then
fn add_two(n_str: &str) -> Result<i32, ParseIntError> {
    //n_str.parse::<i32>().map(|n| n + 2)
    n_str.parse::<i32>().and_then(|n| Ok(n + 2))
}

fn main() {
    assert_eq!(add_two("4").unwrap(), 6);

    println!("Success!");
}
