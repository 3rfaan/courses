// You will be provided with an initial array (the first argument in the destroyer function),
// followed by one or more arguments. Remove all elements from the initial array that are of
// the same value as these arguments.

// Note: You have to use the arguments object.

#[allow(dead_code)]
fn destroyer(arr: &mut Vec<i32>, args: &[i32]) -> Vec<i32> {
    // If the integer in the args array is not equal to an element in the arr array then retain
    // (keep) it, else it will get removed
    for arg in args {
        arr.retain(|&x| x != *arg);
    }
    arr.to_vec()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        let mut arr = vec![1, 2, 3, 1, 2, 3];
        let args = vec![2, 3];

        assert_eq!(destroyer(&mut arr, &args), [1, 1]);
    }

    #[test]
    fn test2() {
        let mut arr = vec![1, 2, 3, 5, 1, 2, 3];
        let args = vec![2, 3];

        assert_eq!(destroyer(&mut arr, &args), [1, 5, 1]);
    }

    #[test]
    fn test3() {
        let mut arr = vec![3, 5, 1, 2, 2];
        let args = vec![2, 3, 5];

        assert_eq!(destroyer(&mut arr, &args), [1]);
    }

    #[test]
    fn test4() {
        let mut arr = vec![2, 3, 2, 3];
        let args = vec![2, 3];

        assert_eq!(destroyer(&mut arr, &args).len(), 0);
    }
}
