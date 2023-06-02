// Fix the errors to make the code work.
struct Point<T> {
    x: T,
    y: T,
}

impl Point<f64> {
    fn distance_from_origin(&self) -> f64 {
        (self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}

fn main() {
    let p: Point<f64> = Point { x: 5.0, y: 10.0 }; // or: let p = Point{x: 5 as f32, y: 10 as f32};
    println!("{}", p.distance_from_origin());
}
