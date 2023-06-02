fn main() {
    // The following two are padding with 5 spaces
    println!("Hello {:5}!", "x"); // =>  "Hello x    !"
    println!("Hello {:1$}!", "x", 5); // =>  "Hello x    !"

    /* Fill in the blanks */
    assert_eq!(format!("Hello {1:0$}!", 5, "x"), "Hello x    !");
    assert_eq!(format!("Hello {:width$}!", "x", width = 5), "Hello x    !");

    println!("Success!");
}
