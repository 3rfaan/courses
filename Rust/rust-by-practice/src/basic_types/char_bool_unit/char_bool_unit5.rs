// Make it work, don't modify `implicitly_ret_unit` !
fn main() {
    let _v: () = ();

    let v = (2, 3);
    assert_eq!(_v, implicitly_ret_unit());

    println!("Success!");
}

fn implicitly_ret_unit() {
    println!("I will return a ()");
}

// Don't use this one
fn explicitly_ret_unit() -> () {
    println!("I will return a ()");
}
