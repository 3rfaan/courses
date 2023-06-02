// Make it work
fn main() {
    let f = true;
    let t = true && true;
    assert_eq!(t, f);

    println!("Success!");
}
