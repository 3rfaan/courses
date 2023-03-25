// Fill in the object constructor with the following methods below:
//
// getFirstName()
// getLastName()
// getFullName()
// setFirstName(first)
// setLastName(last)
// setFullName(firstAndLast)
//
// Run the tests to see the expected output for each method.
// The methods that take an argument must accept only one argument and it has to be a string.
// These methods must be the only available means of interacting with the object.

#[allow(dead_code)]
struct Person {
    first_name: String,
    last_name: String,
}

#[allow(dead_code)]
impl Person {
    fn create(first_name: &str, last_name: &str) -> Self {
        Person {
            first_name: first_name.to_string(),
            last_name: last_name.to_string(),
        }
    }

    fn get_first_name(&self) -> &str {
        &self.first_name
    }

    fn get_last_name(&self) -> &str {
        &self.last_name
    }

    fn get_full_name(&self) -> String {
        format!("{} {}", &self.first_name, &self.last_name)
    }

    fn set_first_name(&mut self, first_name: &str) {
        self.first_name = first_name.to_string();
    }

    fn set_last_name(&mut self, last_name: &str) {
        self.last_name = last_name.to_string();
    }

    fn set_full_name(&mut self, first_name: &str, last_name: &str) {
        self.first_name = first_name.to_string();
        self.last_name = last_name.to_string();
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        let bob = Person::create("Bob", "Ross");

        assert_eq!(bob.get_first_name(), "Bob");
    }

    #[test]
    fn test2() {
        let bob = Person::create("Bob", "Ross");

        assert_eq!(bob.get_last_name(), "Ross");
    }

    #[test]
    fn test3() {
        let bob = Person::create("Bob", "Ross");

        assert_eq!(bob.get_full_name(), "Bob Ross".to_string());
    }

    #[test]
    fn test4() {
        let mut bob = Person::create("Bob", "Ross");

        bob.set_first_name("Haskell");

        assert_eq!(bob.get_full_name(), "Haskell Ross".to_string());
    }

    #[test]
    fn test5() {
        let mut bob = Person::create("Bob", "Ross");

        bob.set_first_name("Haskell");
        bob.set_last_name("Curry");

        assert_eq!(bob.get_full_name(), "Haskell Curry".to_string());
    }

    #[test]
    fn test6() {
        let mut bob = Person::create("Bob", "Ross");

        bob.set_full_name("Haskell", "Curry");

        assert_eq!(bob.get_full_name(), "Haskell Curry".to_string());
    }
}
