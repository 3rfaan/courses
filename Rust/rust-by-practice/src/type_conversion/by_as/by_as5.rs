fn main() {
    let arr: [u64; 13] = [0; 13];
    assert_eq!(std::mem::size_of_val(&arr), 8 * 13);
    let a: *const [u64] = &arr;
    let b = a as *const [u8];
    unsafe {
        assert_eq!(std::mem::size_of_val(&*b), 13) // arr: [u8; 13] = 1 * 13 = 13
    }

    println!("Success!");
}
