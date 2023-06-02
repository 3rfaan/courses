use std::num::ParseIntError;

// With the return type rewritten, we use pattern matching without `unwrap()`.
// But it's so Verbose...
fn multiply(n1_str: &str, n2_str: &str) -> Result<i32, ParseIntError> {
    match n1_str.parse::<i32>() {
        Ok(n1) => match n2_str.parse::<i32>() {
            Ok(n2) => Ok(n1 * n2),
            Err(e) => Err(e),
        },
        Err(e) => Err(e),
    }
}

// Rewriting `multiply` to make it succinct
// You should use BOTH of  `and_then` and `map` here.
fn multiply1(n1_str: &str, n2_str: &str) -> Result<i32, ParseIntError> {
    n1_str
        .parse::<i32>()
        .and_then(|n1| n2_str.parse::<i32>().map(|n2| n1 * n2))
}

fn print(result: Result<i32, ParseIntError>) {
    match result {
        Ok(n) => println!("n is {}", n),
        Err(e) => println!("Error: {}", e),
    }
}

fn main() {
    // This still presents a reasonable answer.
    let twenty = multiply1("10", "2");
    print(twenty);

    // The following now provides a much more helpful error message.
    let tt = multiply("t", "2");
    print(tt);

    println!("Success!");
}
