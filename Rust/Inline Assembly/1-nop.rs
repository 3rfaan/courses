use std::arch::asm;

fn main() {
    unsafe {
        asm!("nop"); // NOP (no operation)
    }
}
