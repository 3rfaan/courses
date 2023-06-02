/* Fill in the blank using two aproaches,
and fix the errror */
fn create_fn() -> impl Fn(i32) -> i32 {
    let num = 5;

    // How does the following closure capture the environment variable `num`
    // &T, &mut T, T ?
    move |x| x + num
}

fn main() {
    let fn_plain = create_fn();
    fn_plain(1);
}
