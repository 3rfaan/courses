// Find the missing letter in the passed letter range and return it.

// If all letters are present in the range, return undefined.

#[allow(dead_code)]
#[allow(unused_variables)]
fn fear_not_letter(s: &str) -> Option<char> {
    unimplemented!()
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
