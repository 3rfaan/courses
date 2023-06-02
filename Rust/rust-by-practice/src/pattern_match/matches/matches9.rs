// Fix the errors in-place
fn main() {
    let age = Some(30);
    if let Some(age) = age {
        // Create a new variable with the same name as previous `age`
        assert_eq!(age, 30);
    } // The new variable `age` goes out of scope here

    match age {
        // Match can also introduce a new shadowed variable
        Some(age) => println!("age is a new variable, it's value is {}", age),
        _ => (),
    }
}
