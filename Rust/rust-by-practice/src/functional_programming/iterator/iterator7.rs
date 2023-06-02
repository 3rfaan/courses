// 0, 1, 1, 2, 3, 5, 8, 13, 21, ..
struct Fibonacci {
    curr: u32,
    next: u32,
}

// Implement `Iterator` for `Fibonacci`.
// The `Iterator` trait only requires a method to be defined for the `next` element.
impl Iterator for Fibonacci {
    // We can refer to this type using Self::Item
    type Item = u32;

    /* Implement next method */
    fn next(&mut self) -> Option<Self::Item> {
        let forward = self.curr + self.next;

        self.curr = self.next;
        self.next = forward;

        Some(self.curr)
    }
}

// Returns a Fibonacci sequence generator
fn fibonacci() -> Fibonacci {
    Fibonacci { curr: 0, next: 1 }
}

fn main() {
    let mut fib = fibonacci();
    assert_eq!(fib.next(), Some(1));
    assert_eq!(fib.next(), Some(1));
    assert_eq!(fib.next(), Some(2));
    assert_eq!(fib.next(), Some(3));
    assert_eq!(fib.next(), Some(5));
}
