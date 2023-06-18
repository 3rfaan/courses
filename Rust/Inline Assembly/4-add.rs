use std::arch::asm;

fn main() {
    let mut x: u64 = 3;

    unsafe {
        asm!("add {0}, 5", inout(reg) x); // `x` is input and output
    }

    assert_eq!(x, 8);

    println!("x = {}", x);
}
