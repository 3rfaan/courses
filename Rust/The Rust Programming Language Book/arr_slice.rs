#![allow(unused)]
fn main() {
    let a = [1, 2, 3, 4, 5];

    let slice = &a[1..3];

    println!("{}", slice[0]);

    assert_eq!(slice, &[2, 3]);
}
