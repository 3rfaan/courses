fn main() {
    let mut res = 42;
    let option = Some(12);
    // TODO: Fix the Clippy lint.
    if let Some(n) = option {
        res += n;
    }

    println!("{res}");
}
