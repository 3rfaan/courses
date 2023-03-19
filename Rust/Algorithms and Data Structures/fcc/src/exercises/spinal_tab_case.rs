// Convert a string to spinal case. Spinal case is all-lowercase-words-joined-by-dashes.

use regex::Regex;

#[allow(dead_code)]
fn spinal_case(mut s: String) -> String {
    // Regex for checking if the string is in camelCase
    let re = Regex::new(r"(?P<lower>[a-z])(?P<upper>[A-Z])").unwrap();

    // Splitting up "camelCase" to "camel Case"
    s = re.replace_all(&s, "${lower} ${upper}").to_string();

    // Regex to define delimiter for split method
    let re = Regex::new(r"\s|_").unwrap();

    // Split string at delimiter (either whitespace or underscore) then collecting them into a
    // vector then iterating over it and switching every string in the vector to lowercase, then
    // join the vector of strings to a single string with '-' as delimiter
    re.split(&s)
        .collect::<Vec<&str>>()
        .into_iter()
        .map(|s| s.to_lowercase())
        .collect::<Vec<String>>()
        .join("-")
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
