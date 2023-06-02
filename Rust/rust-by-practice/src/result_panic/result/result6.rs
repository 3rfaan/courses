use std::num::ParseIntError;

// FILL in the blank
type Res<i32> = Result<i32, ParseIntError>;

// Use the above alias to refer to our specific `Result` type.
fn multiply(first_number_str: &str, second_number_str: &str) -> Res<i32> {
    first_number_str.parse::<i32>().and_then(|first_number| {
        second_number_str
            .parse::<i32>()
            .map(|second_number| first_number * second_number)
    })
}

// Here, the alias again allows us to save some space.
fn print(result: Res<i32>) {
    match result {
        Ok(n) => println!("n is {}", n),
        Err(e) => println!("Error: {}", e),
    }
}

fn main() {
    print(multiply("10", "2"));
    print(multiply("t", "2"));

    println!("Success!");
}
