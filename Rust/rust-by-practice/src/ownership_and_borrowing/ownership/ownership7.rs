fn main() {
    let x = Box::new(5);

    let mut y = Box::new(1); // or let y = &mut 1;

    *y = 4;

    assert_eq!(*x, 5);

    println!("Success!");
}
