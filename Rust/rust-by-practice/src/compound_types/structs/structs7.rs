// Fill the blanks to make the code work
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

fn main() {
    let scale = 2;
    let rect1 = Rectangle {
        width: dbg!(30 * scale), // Print debug info to stderr and assign the value of  `30 * scale` to `width`
        height: 50,
    };

    dbg!(&rect1); // Print debug info to stderr

    println!("{:?}", rect1); // Print debug info to stdout
}
