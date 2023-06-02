// FIX the errors
fn main() {
    let mut v = vec![1, 2, 3];

    let slice1 = &v[..];
    // Out of bounds will cause a panic
    // You must use `v.len` here
    let slice2 = &v[0..v.len()];

    assert_eq!(slice1, slice2);

    // Slices are read only
    // Note: slice and &Vec are different
    let vec_ref: &mut Vec<i32> = &mut v;
    (*vec_ref).push(4);
    let slice3 = &mut v[0..];

    assert_eq!(slice3, &[1, 2, 3, 4]);

    println!("Success!");
}
