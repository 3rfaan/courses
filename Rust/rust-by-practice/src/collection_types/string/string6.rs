// Modify the code below to print out:
// 25
// 25
// 25
// Here, there’s no need to allocate more memory inside the loop.
fn main() {
    let mut s = String::with_capacity(25);

    println!("capacity of s = {}", s.capacity());

    for _ in 0..2 {
        s.push_str("hello");
        println!("capacity of s = {}", s.capacity());
    }

    println!("Success!");
}
