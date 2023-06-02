struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    // Complete the area method which return the area of a Rectangle.
    fn area(&self) -> u32 {
        self.width * self.height
    }
}

fn main() {
    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };

    assert_eq!(rect1.area(), 1500);

    println!("Success!");
}
