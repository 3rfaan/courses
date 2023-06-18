use std::arch::asm;

fn main() {
    let x: u64 = 3;
    let y: u64;

    unsafe {
        asm!("add {0}, 5", inout(reg) x => y); // `x` is input, `y` is output
    }

    assert_eq!(y, 8);

    println!("y = {}", y);
}
