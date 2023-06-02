fn main() {
    // impl From<bool> for i32
    let i1: i32 = false.into();
    let i2: i32 = i32::from(false);
    assert_eq!(i1, i2);
    assert_eq!(i1, 0);

    // FIX the error in two ways
    // 1. impl From<char> for ? , maybe you should check the docs mentioned above to find the answer
    // 2. a keyword from the last chapter
    let i3: u32 = 'a'.into(); // From<char> not implemented for `i32`, u32::from('a');

    // FIX the error in two ways
    let s: String = 'a'.into(); // String::from('a');

    println!("Success!");
}
