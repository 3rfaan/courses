use std::arch::asm;

fn mul(a: u64, b: u64) -> u128 {
    let lo: u64;
    let hi: u64;

    unsafe {
        asm!(
        "mul {}",
        in(reg) a, // put `a` in arbitrary register
        inlateout("rax") b => lo,  // implicit, lower 64 bits stored in `rax`
        lateout("rdx") hi // higher 64 bits stored in `rdx`
        );
    }

    ((hi as u128) << 64) + lo as u128 // left shift `hi` by 64 and add `lo` to form unsiged 128 bit
                                      // return type
}

fn main() {
    println!("mul(3, 5) -> {}", mul(3, 5));
}
