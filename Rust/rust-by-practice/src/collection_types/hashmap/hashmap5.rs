// FIX the errors with least changes
// DON'T remove any code line
use std::collections::HashMap;
fn main() {
    let v1 = 10;
    let mut m1 = HashMap::new();
    m1.insert(v1, v1);
    println!("v1 is still usable after inserting to hashmap : {}", v1);

    let v2 = "hello".to_string(); // or: let v2: &str = "hello";
    let mut m2 = HashMap::new();
    // Ownership moved here
    m2.insert(v2.as_str(), v1);

    assert_eq!(v2, "hello");

    println!("Success!");
}
