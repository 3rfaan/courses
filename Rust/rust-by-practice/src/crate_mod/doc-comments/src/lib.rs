//! # Doc comments
//!
//! A library for showing how to use doc comments/
pub mod compute;

/// Add two values together and return the sum of the two values
///
/// # Examples
///
/// ```
/// let arg1 = 2;
/// let arg2 = 2;
/// let answer = doc_comments::add(arg1, arg2);
///
/// assert_eq!(4, answer);
/// ```
pub fn add(left: usize, right: usize) -> usize {
    left + right
}

/// Add two to the given value and return a new value
///
/// # Examples
///
///```
///let arg = 5;
///let answer = doc_comments::add_two(arg);
///
///assert_eq!(7, answer);
///```
pub fn add_two(x: i32) -> i32 {
    x + 2
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let result = add(2, 2);
        assert_eq!(result, 4);
    }
}
