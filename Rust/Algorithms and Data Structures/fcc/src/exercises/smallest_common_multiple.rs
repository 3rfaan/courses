fn smallest_commons(mut arr: [i32; 2]) -> i32 {
    // Sorting the two numbers so the smaller one is at index 0 and the bigger one at 1
    arr.sort();

    // Destructuring array so the meaning is more clear
    let (start, end) = (arr[0], arr[1]);

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
