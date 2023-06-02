fn main() {
    let mut s = String::new();

    let update_string = |str| s.push_str(str);

    exec(update_string);

    println!("{:?}", s);
}

/* Fill in the blank */
fn exec<'a, F: FnMut(&'a str)>(mut f: F) {
    // or: FnOnce(&'a str)
    f("hello")
}
