// Convert the characters &, <, >, " (double quote), and ' (apostrophe),
// in a string to their corresponding HTML entities.

// Some characters and their corresponding HTML entities
const ENTITIES: [(&str, &str); 5] = [
    ("&", "&amp;"),
    ("<", "&lt;"),
    (">", "&gt;"),
    ("\"", "&quot;"),
    ("'", "&apos;"),
];

#[allow(dead_code)]
fn convert_html(s: &str) -> String {
    let mut result = String::from(s);

    // Iterating over the array of tuples containing character, entity pairs
    for (c, e) in ENTITIES {
        // Replacing characters with their corresponding HTML entities
        result = result.replace(c, e);
    }
    result
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        assert_eq!(convert_html("Dolce & Gabbana"), "Dolce &amp; Gabbana");
    }

    #[test]
    fn test2() {
        assert_eq!(
            convert_html("Hamburgers < Pizza < Tacos"),
            "Hamburgers &lt; Pizza &lt; Tacos"
        );
    }

    #[test]
    fn test3() {
        assert_eq!(convert_html("Sixty > twelve"), "Sixty &gt; twelve");
    }

    #[test]
    fn test4() {
        assert_eq!(
            convert_html("Stuff in \"quotation marks\""),
            "Stuff in &quot;quotation marks&quot;"
        );
    }

    #[test]
    fn test5() {
        assert_eq!(convert_html("Schindler's List"), "Schindler&apos;s List");
    }

    #[test]
    fn test6() {
        assert_eq!(convert_html("<>"), "&lt;&gt;");
    }

    #[test]
    fn test7() {
        assert_eq!(convert_html("abc"), "abc");
    }
}
