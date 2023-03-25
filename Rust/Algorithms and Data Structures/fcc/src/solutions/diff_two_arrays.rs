// Compare two arrays and return a new array with any items only found in one of the two given arrays,
// but not both. In other words, return the symmetric difference of the two arrays.

// Note: You can return the array with its elements in any order.

#[allow(dead_code)]
fn diff_array<'a>(arr1: Vec<&'a str>, arr2: Vec<&'a str>) -> Vec<&'a str> {
    let mut new_arr = Vec::new();

    // Pushing all content of arr1 into new vector
    for string in arr1 {
        new_arr.push(string);
    }

    // Check if arr1 contains strings of arr2, if it does delete the string, else push it
    for string in arr2 {
        if new_arr.contains(&string) {
            // Find out index of the given string
            let index = new_arr.iter().position(|&x| x == string).unwrap();

            // Remove the string at the given index
            new_arr.remove(index);
        } else {
            // Else we push the string to new_arr
            new_arr.push(string);
        }
    }

    // Sorting alphabetically
    new_arr.sort_by(|a, b| a.to_lowercase().cmp(&b.to_lowercase()));

    new_arr
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        let arr1 = vec![
            "diorite",
            "andesite",
            "grass",
            "dirt",
            "pink wool",
            "dead shrub",
        ];
        let arr2 = vec!["diorite", "andesite", "grass", "dirt", "dead shrub"];

        assert_eq!(diff_array(arr1, arr2), ["pink wool"]);
    }

    #[test]
    fn test2() {
        let arr1 = vec!["andesite", "grass", "dirt", "pink wool", "dead shrub"];
        let arr2 = vec!["diorite", "andesite", "grass", "dirt", "dead shrub"];

        assert_eq!(diff_array(arr1, arr2), ["diorite", "pink wool"]);
    }

    #[test]
    fn test3() {
        let arr1 = vec!["andesite", "grass", "dirt", "dead shrub"];
        let arr2 = vec!["andesite", "grass", "dirt", "dead shrub"];

        assert_eq!(diff_array(arr1, arr2).len(), 0);
    }
}
