// Convert a string to spinal case. Spinal case is all-lowercase-words-joined-by-dashes.

#[allow(dead_code)]
#[allow(unused_variables)]
fn spinal_case(s: String) -> String {
    unimplemented!()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        assert_eq!(
            spinal_case("This Is Spinal Tap".to_string()),
            "this-is-spinal-tap"
        );
    }

    #[test]
    fn test2() {
        assert_eq!(
            spinal_case("thisIsSpinalTap".to_string()),
            "this-is-spinal-tap"
        );
    }

    #[test]
    fn test3() {
        assert_eq!(
            spinal_case("The_Andy_Griffith_Show".to_string()),
            "the-andy-griffith-show"
        );
    }

    #[test]
    fn test4() {
        assert_eq!(
            spinal_case("Teletubbies say Eh-oh".to_string()),
            "teletubbies-say-eh-oh"
        );
    }
}
