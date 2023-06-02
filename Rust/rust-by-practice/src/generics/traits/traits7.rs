fn main() {
    assert_eq!(sum(1, 2), 3);
}

// Implement `fn sum` with trait bound in two ways.
fn sum<T: std::ops::Add<Output = T>>(x: T, y: T) -> T {
    x + y
}
// or: use `where`
