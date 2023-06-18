use std::arch::asm;

fn main() {
    let mut a: u64 = 4;
    let b: u64 = 4;

    unsafe {
        asm!(
        "add {0}, {1}", // adds `b` to `a` and store it in `a`
        inlateout(reg) a, in(reg) b,
        options(pure, nomem, nostack),
        );
    }

    assert_eq!(a, 8);

    println!("a = {}", a);
}
