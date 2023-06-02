use crate::compound_types::enums::enums6::List::*;

enum List {
    Cons(u32, Box<List>),
    Nil,
}

impl List {
    fn new() -> List {
        Nil
    }

    fn prepend(self, elem: u32) -> List {
        Cons(elem, Box::new(self))
    }

    fn len(&self) -> u32 {
        match *self {
            Cons(_, ref tail) => 1 + tail.len(),
            Nil => 0,
        }
    }

    fn stringify(&self) -> String {
        match *self {
            Cons(head, ref tail) => {
                // `format!` is similar to `print!`, but returns a heap
                // allocated string instead of printing to the console
                format!("{}, {}", head, tail.stringify())
            }
            Nil => format!("Nil"),
        }
    }
}

fn main() {
    let mut list = List::new(); // Nil

    list = list.prepend(1); // Cons(1, Nil)
    list = list.prepend(2); // Cons(2, Cons(1, Nil))
    list = list.prepend(3); // Cons(3, Cons(2, Cons(1, Nil)))

    println!("linked list has length: {}", list.len()); // 3
    println!("{}", list.stringify()); // 3, 2, 1, Nil
}
