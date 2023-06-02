struct Point<T, U> {
    x: T,
    y: U,
}

impl<T, U> Point<T, U> {
    // Implement mixup to make it work, DON'T modify other code.
    fn mixup<V, W>(self, other: Point<V, W>) -> Point<T, W> {
        Point {
            x: self.x,
            y: other.y,
        }
    }
}

fn main() {
    let p1 = Point { x: 5, y: 10 };
    let p2 = Point {
        x: "Hello",
        y: '中',
    };

    let p3 = p1.mixup(p2);

    assert_eq!(p3.x, 5);
    assert_eq!(p3.y, '中');

    println!("Success!");
}
