use std::arch::asm;

fn main() {
    let i: u64 = 3;
    let o: u64;

    unsafe {
        asm!(
        "mov {0}, {1}", // copy value from `i` to `o`
        "add {0}, 5",   // add 5 to `o` and store it there
        out(reg) o, // output
        in(reg) i, // input
        );
    }

    assert_eq!(o, 8);

    println!("o = {}", o);
}
