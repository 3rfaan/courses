// Remove a line in the code to make it compile
fn main() {
    let mut x: i32 = 1;
    x = 7;

    // Shadowing and re-binding
    x += 3;
    println!("x = {}", x);

    let _y = 4;
    // Shadowing
    let _y = "I can also be bound to text!";

    println!("Success!");
}
