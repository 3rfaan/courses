use std::arch::asm;

fn main() {
    let mut a: u64 = 4;
    let b: u64 = 4;
    let c: u64 = 4;

    unsafe {
        asm!(
        "add {0}, {1}", // add a, b -> 4 + 4 -> `a` = 8
        "add {0}, {2}", // add a, c -> 8 + 4 -> `a` = 12
        inout(reg) a,
        in(reg) b,
        in(reg) c,
        );
    }

    assert_eq!(a, 12);

    println!("a = {}", a);
}
