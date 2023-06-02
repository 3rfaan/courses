// Fix the errors
enum Message {
    Hello { id: i32 },
}

fn main() {
    let msg = Message::Hello { id: 5 };

    match msg {
        Message::Hello { id: id @ 3..=7 } => println!("Found an id in range [3, 7]: {}", id),
        Message::Hello {
            id: newid @ (10 | 11 | 12),
        } => {
            println!("Found an id in another range [10, 12]: {}", newid)
        }
        Message::Hello { id } => println!("Found some other id: {}", id),
    }
}
