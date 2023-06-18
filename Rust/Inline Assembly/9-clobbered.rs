use std::arch::asm;

fn main() {
    let mut name_buf = [0_u8; 12]; // [0, 0, 0, .., 0] (12 times)

    unsafe {
        asm!(
        "push rbx",
        "cpuid",
        "mov [rdi], rbx",
        "mov [rdi + 4], rdx",
        "mov [rdi + 8], rcx",
        "pop rbx",

        in("rdi") name_buf.as_mut_ptr(),
        inout("eax") 0 => _,
        out("ecx") _,
        out("edx") _,
        );
    }

    let name = core::str::from_utf8(&name_buf).unwrap();

    println!("CPU Manufacturer ID: {}", name);
}
