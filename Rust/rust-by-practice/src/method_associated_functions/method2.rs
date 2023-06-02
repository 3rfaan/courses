// Only fill in the blanks, DON'T remove any line!
#[derive(Debug)]
struct TrafficLight {
    color: String,
}

impl TrafficLight {
    pub fn show_state(&self) {
        println!("the current state is {}", self.color);
    }
}
fn main() {
    let light = TrafficLight {
        color: "red".to_owned(),
    };
    // Don't take the ownership of `light` here.
    light.show_state();
    // ... Otherwise, there will be an error below
    println!("{:?}", light);
}
