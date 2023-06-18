use std::arch::asm;

fn load_fpu_control_word(control: u16) {
    unsafe {
        asm!("fldcw [{}]", in(reg) &control, options(nostack));
    }
}

fn main() {
    load_fpu_control_word(0x037F); // 0x037F masks all floating-point exceptions, sets rounding to
                                   // nearest, sets x87 FPU precision to 64 bits
}
