// FILL in the blanks
fn main() {
    let mut values: [i32; 2] = [1, 2];
    let p1: *mut i32 = values.as_mut_ptr();
    let first_address: usize = p1 as usize;
    let second_address = first_address + 4; // 4 == std::mem::size_of::<i32>()
    let p2: *mut i32 = second_address as *mut i32; // p2 points to the 2nd element in values
    unsafe {
        // Add one to the second element
        *p2 += 1;
    }

    assert_eq!(values[1], 3);

    println!("Success!");
}
