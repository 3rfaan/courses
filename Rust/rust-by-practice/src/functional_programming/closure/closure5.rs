/* Make it work by changing the trait bound, in two ways*/
fn fn_once<F>(func: F)
where
    F: FnOnce(usize) -> bool + Copy, // or: F: Fn(usize) -> bool,
{
    println!("{}", func(3));
    println!("{}", func(4));
}

fn main() {
    let x = vec![1, 2, 3];
    fn_once(|z| z == x.len())
}
