use std::arch::asm;

fn main() {
    let mut a: u64 = 4;
    let b: u64 = 4;

    unsafe {
        asm!("add {0}, {1}", inlateout(reg) a, in(reg) b); // add a, b -> 4 + 4 -> `a` = 8
    }

    assert_eq!(a, 8);

    println!("a = {}", 8);
}
