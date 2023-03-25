// Given a positive integer num, return the sum of all odd Fibonacci numbers that are less than or equal to num.

// The first two numbers in the Fibonacci sequence are 0 and 1. Every additional number in the sequence is the sum of the two previous numbers.
// The first seven numbers of the Fibonacci sequence are 0, 1, 1, 2, 3, 5 and 8.

// For example, sumFibs(10) should return 10 because all odd Fibonacci numbers less than or equal to 10 are 1, 1, 3, and 5.

#[allow(dead_code)]
fn sum_fibs(num: i64) -> i64 {
    // Starting with 0 and 1 where 1 is the current number
    let mut prev = 0;
    let mut curr = 1;

    // Variable for storing the sum
    let mut sum = 0;

    // Loop until current number is equal to "num" argument
    while curr <= num {
        // If the current number is odd then add it to the "sum" variable
        if curr % 2 == 1 {
            sum += curr;
        }

        // The next number is the previous number added to the current number
        let next = prev + curr;

        // Rotating the number where current becomes previous and next becomes current, then
        // looping again
        prev = curr;
        curr = next;
    }
    sum
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        assert_eq!(sum_fibs(1000), 1785);
    }

    #[test]
    fn test2() {
        assert_eq!(sum_fibs(4000000), 4613732);
    }

    #[test]
    fn test3() {
        assert_eq!(sum_fibs(4), 5);
    }

    #[test]
    fn test4() {
        assert_eq!(sum_fibs(75024), 60696);
    }

    #[test]
    fn test5() {
        assert_eq!(sum_fibs(75025), 135721);
    }
}
