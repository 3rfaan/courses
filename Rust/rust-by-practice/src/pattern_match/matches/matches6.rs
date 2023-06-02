fn main() {
    let o = Some(7);

    if let Some(i) = o {
        println!("This is a really long string and `{:?}`", i);
    }
}
