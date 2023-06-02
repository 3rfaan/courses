// Modify `4` in assert to make it work
use std::mem::size_of_val;
fn main() {
    let unit: () = ();

    println!("size of unit = {}", size_of_val(&unit));
    assert!(size_of_val(&unit) == 0);

    println!("Success!");
}
