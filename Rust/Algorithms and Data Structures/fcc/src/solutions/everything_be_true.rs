// Check if the predicate (second argument) is truthy on all elements of a collection (first argument).

// In other words, you are given an array collection of objects.
// The predicate pre will be an object property and you need to return true if its value is truthy. Otherwise, return false.

// In JavaScript, truthy values are values that translate to true when evaluated in a Boolean context.

// Remember, you can access object properties through either dot notation or [] notation.

// Enum to hold Person or Pokemon type so both types can be passed as argument for truth_check()
#[derive(PartialEq)]
#[allow(dead_code)]
enum Type {
    Person(Person),
    Pokemon(Pokemon),
}

// Methods returning value of certain field
impl Type {
    fn name(&self) -> &str {
        match self {
            Type::Person(pers) => &pers.name,
            _ => panic!("Not valid type"),
        }
    }

    fn role(&self) -> &str {
        match self {
            Type::Person(pers) => &pers.role,
            _ => panic!("Not a valid type"),
        }
    }

    fn is_bot(&self) -> bool {
        match self {
            Type::Person(pers) => pers.is_bot,
            _ => panic!("Not a valid type"),
        }
    }

    fn number(&self) -> i32 {
        match self {
            Type::Pokemon(pkmn) => pkmn.number,
            _ => panic!("Not a valid type"),
        }
    }

    fn caught(&self) -> i32 {
        match self {
            Type::Pokemon(pkmn) => pkmn.caught,
            _ => panic!("Not a valid type"),
        }
    }
}

#[derive(PartialEq)]
struct Person {
    name: String,
    role: String,
    is_bot: bool,
}

#[derive(PartialEq)]
struct Pokemon {
    name: String,
    number: i32,
    caught: i32,
}

#[allow(dead_code)]
fn truth_check(collection: Vec<Type>, pre: &str) -> bool {
    // Itering over vector of elements either of Person or Pokemon type and emulating JavaScript
    // falsy values to check if everything is truthy (values that are true in a Boolean context)
    collection.iter().all(|p| match pre {
        "name" => p.name() != "",
        "role" => p.role() != "",
        "is_bot" => p.is_bot() != false,
        "number" => p.number() != 0,
        "caught" => p.caught() != 0,
        _ => panic!("No field name found for {pre}"),
    })
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        let p1: Person = Person {
            name: String::from("Quincy"),
            role: String::from("Founder"),
            is_bot: false,
        };

        let p2: Person = Person {
            name: String::from("Naomi"),
            role: String::from(""),
            is_bot: false,
        };

        let p3: Person = Person {
            name: String::from("Camperbot"),
            role: String::from("Bot"),
            is_bot: true,
        };

        let collection = vec![Type::Person(p1), Type::Person(p2), Type::Person(p3)];

        assert_eq!(truth_check(collection, "is_bot"), false);
    }

    #[test]
    fn test2() {
        let p1: Person = Person {
            name: String::from("Quincy"),
            role: String::from("Founder"),
            is_bot: false,
        };

        let p2: Person = Person {
            name: String::from("Naomi"),
            role: String::from(""),
            is_bot: false,
        };

        let p3: Person = Person {
            name: String::from("Camperbot"),
            role: String::from("Bot"),
            is_bot: true,
        };

        let collection = vec![Type::Person(p1), Type::Person(p2), Type::Person(p3)];

        assert_eq!(truth_check(collection, "name"), true);
    }

    #[test]
    fn test3() {
        let p1: Person = Person {
            name: String::from("Quincy"),
            role: String::from("Founder"),
            is_bot: false,
        };

        let p2: Person = Person {
            name: String::from("Naomi"),
            role: String::from(""),
            is_bot: false,
        };

        let p3: Person = Person {
            name: String::from("Camperbot"),
            role: String::from("Bot"),
            is_bot: true,
        };

        let collection = vec![Type::Person(p1), Type::Person(p2), Type::Person(p3)];

        assert_eq!(truth_check(collection, "role"), false);
    }

    #[test]
    fn test4() {
        let pkmn1: Pokemon = Pokemon {
            name: String::from("Pikachu"),
            number: 25,
            caught: 3,
        };

        let pkmn2: Pokemon = Pokemon {
            name: String::from("Togepi"),
            number: 175,
            caught: 1,
        };

        let collection = vec![Type::Pokemon(pkmn1), Type::Pokemon(pkmn2)];

        assert_eq!(truth_check(collection, "number"), true);
    }
}
