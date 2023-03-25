// Find the smallest common multiple of the provided parameters that can be evenly divided by both,
// as well as by all sequential numbers in the range between these parameters.

// The range will be an array of two numbers that will not necessarily be in numerical order.

// For example, if given 1 and 3, find the smallest common multiple of both 1 and 3 that is also
// evenly divisible by all numbers between 1 and 3. The answer here would be 6.

#[allow(dead_code)]
fn smallest_commons(mut arr: [i32; 2]) -> i32 {
    // Sorting the two numbers so the smaller one is at index 0 and the bigger one at 1
    arr.sort();

    // Destructuring array so the meaning is more clear
    let (start, end) = (arr[0], arr[1]);

    // From the range of start to end (e.g. 1 to 5) multiplying each number in the range by the
    // accumulator value and dividing the result by the greatest common divisor of the
    // accumulator value
    let lcm = (start..=end).fold(start, |acc, n| (acc * n) / gcd(acc, n));

    lcm
}

// Function to find the greatest common divisor of two ints using recursion
fn gcd(a: i32, b: i32) -> i32 {
    match b {
        0 => a,
        _ => gcd(b, a % b),
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        assert_eq!(smallest_commons([1, 5]), 60);
    }

    #[test]
    fn test2() {
        assert_eq!(smallest_commons([5, 1]), 60);
    }

    #[test]
    fn test3() {
        assert_eq!(smallest_commons([2, 10]), 2520);
    }

    #[test]
    fn test4() {
        assert_eq!(smallest_commons([1, 13]), 360360);
    }

    #[test]
    fn test5() {
        assert_eq!(smallest_commons([23, 18]), 6056820);
    }
}
