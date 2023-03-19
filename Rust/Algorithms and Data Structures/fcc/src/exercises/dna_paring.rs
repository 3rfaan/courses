// Pairs of DNA strands consist of nucleobase pairs. Base pairs are represented by the characters AT and CG,
// which form building blocks of the DNA double helix.

// The DNA strand is missing the pairing element. Write a function to match the missing base pairs for the provided DNA strand.
// For each character in the provided string, find the base pair character. Return the results as a 2d array.

// For example, for the input GCG, return [["G", "C"], ["C","G"], ["G", "C"]]

// The character and its pair are paired up in an array, and all the arrays are grouped into one encapsulating array.

#[allow(dead_code)]
fn pair_element(s: &str) -> Vec<[char; 2]> {
    // Vector for pairs which will be returned
    let mut pairs = Vec::new();

    // Iterating over characters in string "s"
    for c in s.chars() {
        pairs.push(match_base_pair(c));
    }
    pairs
}

// Function to return an array of 2 chars with the matching base DNA pair
fn match_base_pair(c: char) -> [char; 2] {
    match c {
        'A' => ['A', 'T'],
        'T' => ['T', 'A'],
        'C' => ['C', 'G'],
        'G' => ['G', 'C'],
        _ => panic!("Invalid DNA character: {c}"),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        assert_eq!(
            pair_element("ATCGA"),
            vec![['A', 'T'], ['T', 'A'], ['C', 'G'], ['G', 'C'], ['A', 'T']]
        );
    }

    #[test]
    fn test2() {
        assert_eq!(
            pair_element("TTGAG"),
            vec![['T', 'A'], ['T', 'A'], ['G', 'C'], ['A', 'T'], ['G', 'C']],
        )
    }

    #[test]
    fn test3() {
        assert_eq!(
            pair_element("CTCTA"),
            vec![['C', 'G'], ['T', 'A'], ['C', 'G'], ['T', 'A'], ['A', 'T']],
        )
    }
}
