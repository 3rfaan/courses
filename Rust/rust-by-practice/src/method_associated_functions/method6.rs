#[derive(Debug)]
enum TrafficLightColor {
    Red,
    Yellow,
    Green,
}

// Implement TrafficLightColor with a method.
impl TrafficLightColor {
    fn color(&self) -> &'static str {
        match *self {
            Self::Red => "red",
            Self::Yellow => "yellow",
            Self::Green => "green",
        }
    }
}

fn main() {
    let c = TrafficLightColor::Yellow;

    assert_eq!(c.color(), "yellow");

    println!("{:?}", c);
}
