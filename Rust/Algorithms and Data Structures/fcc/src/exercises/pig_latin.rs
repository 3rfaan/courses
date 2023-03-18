use regex::Regex;

#[allow(dead_code)]
fn translate_pig_latin(s: String) -> String {
    let re = Regex::new(r"^[aeiou]+").unwrap();
    let mut result = String::new();

    if re.is_match(&s) {
        result.push_str(&s);
        result.push_str("way");
    } else {
        let re = Regex::new(r"(?P<first>^[^aeiou]+)(?P<rest>\w*)").unwrap();

        result = re.replace(&s, "${rest}${first}ay").to_string();
    }
    result
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        assert_eq!(
            translate_pig_latin("california".to_string()),
            "aliforniacay"
        );
    }

    #[test]
    fn test2() {
        assert_eq!(
            translate_pig_latin("paragraphs".to_string()),
            "aragraphspay"
        );
    }

    #[test]
    fn test3() {
        assert_eq!(translate_pig_latin("glove".to_string()), "oveglay");
    }

    #[test]
    fn test4() {
        assert_eq!(translate_pig_latin("algorithm".to_string()), "algorithmway");
    }
}
