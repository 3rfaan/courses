// Given the array arr, iterate through and remove each element starting from the first element (the 0 index)
// until the function func returns true when the iterated element is passed through it.

// Then return the rest of the array once the condition is satisfied,
// otherwise, arr should be returned as an empty array.

#[allow(dead_code)]
fn drop_elements<F>(arr: &mut Vec<i32>, filter: F) -> Vec<i32>
where
    F: Fn(&i32) -> bool,
{
    for (i, value) in arr.iter().enumerate() {
        if filter(value) {
            return arr[i..].to_vec();
        }
    }
    vec![]
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        assert_eq!(
            drop_elements(&mut vec![1, 2, 3, 4], |&n| n >= 3),
            vec![3, 4]
        );
    }

    #[test]
    fn test2() {
        assert_eq!(
            drop_elements(&mut vec![0, 1, 0, 1], |&n| n == 1),
            vec![1, 0, 1]
        );
    }

    #[test]
    fn test3() {
        assert_eq!(drop_elements(&mut vec![1, 2, 3], |&n| n > 0), vec![1, 2, 3]);
    }

    #[test]
    fn test4() {
        assert_eq!(drop_elements(&mut vec![1, 2, 3, 4], |&n| n > 5), vec![]);
    }

    #[test]
    fn test5() {
        assert_eq!(
            drop_elements(&mut vec![1, 2, 3, 7, 4], |&n| n > 3),
            vec![7, 4]
        );
    }

    #[test]
    fn test6() {
        assert_eq!(
            drop_elements(&mut vec![1, 2, 3, 9, 2], |&n| n > 2),
            vec![3, 9, 2]
        );
    }
}
