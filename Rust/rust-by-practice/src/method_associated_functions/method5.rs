struct Rectangle {
    width: u32,
    height: u32,
}

// Using multiple `impl` blocks to rewrite the code below.
impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }
}

impl Rectangle {
    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

fn main() {
    println!("Success!");
}
