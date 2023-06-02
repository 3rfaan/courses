#[derive(Debug)]
struct Person {
    name: String,
    age: u8,
}

fn main() {
    let person = Person {
        name: "Sunface".to_string(),
        age: 18,
    };

    /* Make it output:
    Person {
        name: "Sunface",
        age: 18,
    }
    */
    println!("{:#?}", person);
}
