use std::arch::asm;

fn main() {
    let mut a: u64 = 0;

    unsafe {
        asm!(
        "mov {0}, 10",  // move 10 into `a`
        "2:",           // label 2 (2b in context)
        "sub {0}, 1",   // subtract 1 from `a`
        "cmp {0}, 3",   // compare `a` with 3
        "jle 2f",       // jump to label `2f` if `a` is less than or equal to 3
        "jmp 2b",       // jump to label `2b` (loop back)
        "2:",           // label 2 (2f in context)
        "add {0}, 2",   // add 2 to `a`
        inout(reg) a
        );
    }

    assert_eq!(a, 5);

    println!("a = {}", a);
}
