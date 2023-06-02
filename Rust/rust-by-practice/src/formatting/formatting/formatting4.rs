fn main() {
    // Left align
    println!("Hello {:<5}!", "x"); // => Hello x    !
                                   // Right align
    assert_eq!(format!("Hello {:>5}!", "x"), "Hello     x!");
    // Center align
    assert_eq!(format!("Hello {:^5}!", "x"), "Hello   x  !");

    // Left align, pad with '&'
    assert_eq!(format!("Hello {:&<5}!", "x"), "Hello x&&&&!");

    println!("Success!");
}
