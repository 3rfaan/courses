// Make it work with two ways
fn main() {
    let v = {
        let mut x = 1;
        x += 2;
        x
    };

    assert_eq!(v, 3); // or assert_eq!(v, ());

    println!("Success!");
}
