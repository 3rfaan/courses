// Find the missing letter in the passed letter range and return it.

// If all letters are present in the range, return undefined.

#[allow(dead_code)]
fn fear_not_letter(s: &str) -> Option<char> {
    // Using the chars() method to iterate over the next char and typecasting then into u8, the
    // next() method returns "None" if "s" is empty
    let mut curr_char_code = s.chars().next()? as u8;
    let mut missing = None;

    // Iterating over the characters in string "s"
    for c in s.chars() {
        // If the character in "s" is equal to the current character code then we increment the
        // ASCII value of curr_char_code by one to go one letter further and then check again
        if c as u8 == curr_char_code {
            curr_char_code += 1;
        }
        // Else we found the missing character and store it in the variable "missing" which we
        // then return
        else {
            missing = Some(curr_char_code as char);
            break;
        }
    }
    missing
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        assert_eq!(fear_not_letter("abce"), Some('d'));
    }

    #[test]
    fn test2() {
        assert_eq!(fear_not_letter("abcdefghjklmno"), Some('i'));
    }

    #[test]
    fn test3() {
        assert_eq!(fear_not_letter("stvwx"), Some('u'));
    }

    #[test]
    fn test4() {
        assert_eq!(fear_not_letter("bcdf"), Some('e'));
    }

    #[test]
    fn test5() {
        assert_eq!(fear_not_letter("abcdefghijklmnopqrstuvwxyz"), None);
    }
}
