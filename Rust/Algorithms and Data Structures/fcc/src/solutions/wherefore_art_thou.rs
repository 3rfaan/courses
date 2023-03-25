// Make a function that looks through an array of objects (first argument) and returns an array of all objects
// that have matching name and value pairs (second argument).
// Each name and value pair of the source object has to be present in the object
// from the collection if it is to be included in the returned array.

// For example, if the first argument is
// [{ first: "Romeo", last: "Montague" }, { first: "Mercutio", last: null }, { first: "Tybalt", last: "Capulet" }],
// and the second argument is { last: "Capulet" }, then you must return the third object from the array (the first argument),
// because it contains the name and its value, that was passed on as the second argument.

use std::collections::HashMap;

#[allow(dead_code)]
fn what_is_in_a_name(
    collection: Vec<HashMap<String, String>>,
    source: HashMap<String, String>,
) -> Vec<HashMap<String, String>> {
    // Putting collection vector into consuming iterator
    collection
        .into_iter()
        // Filter over every HashMap in collection (obj)
        .filter(|obj| {
            source
                // Iterating over key, value pairs in source HashMap
                .iter()
                // Checking for all key, value pairs in source if the HashMap in the collection we
                // filter over contains a key of source and the value of the obj is equal the value
                // of the source HashMap
                .all(|(key, value)| obj.contains_key(key) && obj.get(key) == Some(value))
        })
        // Recollecting into vector again
        .collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        let collection = vec![
            HashMap::from([
                ("first".to_string(), "Romeo".to_string()),
                ("last".to_string(), "Montague".to_string()),
            ]),
            HashMap::from([
                ("first".to_string(), "Mercutio".to_string()),
                ("last".to_string(), "null".to_string()),
            ]),
            HashMap::from([
                ("first".to_string(), "Tybalt".to_string()),
                ("last".to_string(), "Capulet".to_string()),
            ]),
        ];
        let query = HashMap::from([("last".to_string(), "Capulet".to_string())]);

        let result = vec![HashMap::from([
            ("first".to_string(), "Tybalt".to_string()),
            ("last".to_string(), "Capulet".to_string()),
        ])];

        assert_eq!(what_is_in_a_name(collection, query), result);
    }
}
