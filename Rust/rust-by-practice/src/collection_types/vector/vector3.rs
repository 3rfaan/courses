// FILL in the blanks
fn main() {
    // Array -> Vec
    // impl From<[T; N]> for Vec
    let arr = [1, 2, 3];
    let v1 = Vec::from(arr);
    let v2: Vec<i32> = arr.into();

    assert_eq!(v1, v2);

    // String -> Vec
    // impl From<String> for Vec
    let s = "hello".to_string();
    let v1: Vec<u8> = s.into();

    let s = "hello".to_string();
    let v2 = s.into_bytes();
    assert_eq!(v1, v2);

    // impl<'_> From<&'_ str> for Vec
    let s = "hello";
    let v3 = Vec::from(s);
    assert_eq!(v2, v3);

    // Iterators can be collected into vectors
    let v4: Vec<i32> = [0; 10].into_iter().collect();
    assert_eq!(v4, vec![0; 10]);

    println!("Success!");
}
