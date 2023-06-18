use std::arch::asm;

fn main() {
    let mut x: u64 = 4;

    unsafe {
        asm!(
        "mov {tmp}, {x}", // mov tmp, 4 -> tmp = 4
        "shl {tmp}, 1", // shl 4, 1 -> 4 << 1 -> tmp = 8
        "shl {x}, 2", // shl 4, 2 -> 4 << 2 -> x = 16
        "add {x}, {tmp}", // add 16, 8 -> 16 + 8 = 24
        x = inout(reg) x,
        tmp = out(reg) _,
        );
    }

    assert_eq!(x, 4 * 6);

    println!("x = {}", x);
}
