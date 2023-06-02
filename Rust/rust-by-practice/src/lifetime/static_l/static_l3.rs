fn main() {
    // Make a `string` literal and print it:
    let static_string = "I'm in read-only memory";
    println!("static_string: {}", static_string);

    // When `static_string` goes out of scope, the reference
    // can no longer be used, but the data remains in the binary.

    println!("static_string reference remains alive: {}", static_string);
}
