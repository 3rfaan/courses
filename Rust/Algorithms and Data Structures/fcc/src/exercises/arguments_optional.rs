#[allow(dead_code)]
fn curry(a: i32) -> impl Fn(i32) -> i32 {
    move |x| a + x
}

#[allow(dead_code)]
fn add_two(a: i32, b: i32) -> i32 {
    a + b
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        assert_eq!(add_two(2, 3), 5);
    }

    #[test]
    fn test2() {
        assert_eq!(add_two(23, 30), 53);
    }

    #[test]
    fn test3() {
        let add_five = curry(5);

        assert_eq!(add_five(7), 12);
    }

    #[test]
    fn test4() {
        let add_twentyfive = curry(25);

        assert_eq!(add_twentyfive(50), 75);
    }
}
