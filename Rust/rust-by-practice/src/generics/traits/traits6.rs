struct Sheep {}
struct Cow {}

trait Animal {
    fn noise(&self) -> String;
}

impl Animal for Sheep {
    fn noise(&self) -> String {
        "baaaaah!".to_string()
    }
}

impl Animal for Cow {
    fn noise(&self) -> String {
        "moooooo!".to_string()
    }
}

// Returns some struct that implements Animal, but we don't know which one at compile time.
// FIX the errors here, you can make a fake random, or you can use trait object.
fn random_animal<'a>(random_number: f64) -> &'a dyn Animal {
    if random_number < 0.5 {
        &Sheep {}
    } else {
        &Cow {}
    }
}

// or:
// fn random_animal(random_number: f64) -> Box<dyn Animal> {
//     if random_number < 0.5 {
//         Box::new(Sheep {})
//     } else {
//         Box::new(Cow {})
//     }
// }

fn main() {
    let random_number = 0.234;
    let animal = random_animal(random_number);
    println!(
        "You've randomly chosen an animal, and it says {}",
        animal.noise()
    );
}
