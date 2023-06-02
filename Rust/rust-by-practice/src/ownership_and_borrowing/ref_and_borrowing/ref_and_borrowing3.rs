// Fix error
fn main() {
    let mut s = String::from("hello, ");

    borrow_object(&s);

    println!("Success!");
}

fn borrow_object(s: &String) {}
