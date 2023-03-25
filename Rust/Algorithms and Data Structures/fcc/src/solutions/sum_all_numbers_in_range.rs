// We'll pass you an array of two numbers.
// Return the sum of those two numbers plus the sum of all the numbers between them.
// The lowest number will not always come first.

// For example, sumAll([4,1]) should return 10 because sum of all the numbers between 1 and 4 (both inclusive) is 10.

#[allow(dead_code)]
pub fn sum_all(arr: &mut [i32; 2]) -> i32 {
    // Sort array (that's why arr is mutable!)
    arr.sort();

    // Take range from first index of slice to last index and sum all the integers in the sum
    // together
    (arr[0]..=arr[1]).sum()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        let mut arg = [1, 4];

        assert_eq!(sum_all(&mut arg), 10);
    }

    #[test]
    fn test2() {
        let mut arg = [4, 1];

        assert_eq!(sum_all(&mut arg), 10);
    }

    #[test]
    fn test3() {
        let mut arg = [5, 10];

        assert_eq!(sum_all(&mut arg), 45);
    }

    #[test]
    fn test4() {
        let mut arg = [10, 5];

        assert_eq!(sum_all(&mut arg), 45);
    }
}
