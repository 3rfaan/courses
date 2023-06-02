use std::num::ParseIntError;

// IMPLEMENT multiply with ?
// DON'T use unwrap here
fn multiply(n1_str: &str, n2_str: &str) -> Result<i32, ParseIntError> {
    let n1: i32 = n1_str.parse()?;
    let n2: i32 = n2_str.parse()?;

    Ok(n1 * n2)
}

fn main() {
    assert_eq!(multiply("3", "4").unwrap(), 12);
    println!("Success!");
}
