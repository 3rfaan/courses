/* Implement `call_me` to make it work */
fn call_me<F: Fn()>(f: F) {
    f();
}

fn function() {
    println!("I'm a function!");
}

fn main() {
    let closure = || println!("I'm a closure!");

    call_me(closure);
    call_me(function);
}
