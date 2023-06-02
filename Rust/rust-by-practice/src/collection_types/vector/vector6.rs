// FIX the errors
fn main() {
    let mut vec = Vec::with_capacity(10);

    // The vector contains no items, even though it has capacity for more
    assert_eq!(vec.len(), 0);
    assert_eq!(vec.capacity(), 10);

    // These are all done without reallocating...
    for i in 0..10 {
        vec.push(i);
    }
    assert_eq!(vec.len(), 10);
    assert_eq!(vec.capacity(), 10);

    println!("{:?}", vec);

    // ...but this may make the vector reallocate
    vec.push(11);
    assert_eq!(vec.len(), 11);
    assert!(vec.capacity() >= 11);

    println!("{:?}", vec);

    // Fill in an appropriate value to make the `for` done without reallocating
    let mut vec = Vec::with_capacity(100);
    for i in 0..100 {
        vec.push(i);
    }

    assert_eq!(vec.len(), 100);
    assert_eq!(vec.capacity(), 100);

    println!("{:?}", vec);

    println!("Success!");
}
