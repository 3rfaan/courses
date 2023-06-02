// Fill in the blank and fix the error
enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}

fn main() {
    let msg = Message::Move { x: 2, y: 2 };

    if let Message::Move { x: a, y: b } = msg {
        assert_eq!(a, b);
    } else {
        panic!("NEVER LET THIS RUN！");
    }

    println!("Success!");
}
