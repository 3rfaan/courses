use std::arch::asm;

extern "C" fn foo(arg: i32) -> i32 {
    println!("arg = {}", arg);

    arg * 2
}

fn call_foo(arg: i32) -> i32 {
    unsafe {
        let result;

        asm!(
        "call {}",
        in(reg) foo, // function pointer to call
        in("rdi") arg, // 1st argument in `rdi`
        out("rax") result, // return value in `rax`
        clobber_abi("C"), // mark all registers not preserved by "C" calling convention as clobbered
        );
        result
    }
}

fn main() {
    let result = call_foo(5);

    assert_eq!(10, result);

    println!("result = {}", result);
}
