// Flatten a nested array. You must account for varying levels of nesting.

#[allow(dead_code)]
enum Value {
    Number(i32),
    Array(Vec<Value>),
}

#[allow(dead_code)]
fn steamroll_array(arr: &[Value]) -> Vec<i32> {
    // Empty vector which holds i32 values
    let mut result = Vec::new();

    // Iterating over each item in array arr
    for val in arr {
        // Matching type of item val
        match val {
            // If number (i32 integer) then push to the result vector
            Value::Number(n) => result.push(*n),
            // If nested vector then recursively call function again with nested vector as
            // argument, then extending the result array with the return value of function
            // call, which is a flattened vector
            Value::Array(sub_arr) => result.extend(steamroll_array(sub_arr)),
        }
    }
    result
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        let arr = [
            Value::Number(1),
            Value::Array(vec![Value::Number(2)]),
            Value::Array(vec![
                Value::Number(3),
                Value::Array(vec![Value::Array(vec![Value::Number(4)])]),
            ]),
        ];

        assert_eq!(steamroll_array(&arr), vec![1, 2, 3, 4]);
    }

    #[test]
    fn test2() {
        let arr = [
            Value::Number(1),
            Value::Array(vec![]),
            Value::Array(vec![
                Value::Number(3),
                Value::Array(vec![Value::Array(vec![Value::Number(4)])]),
            ]),
        ];

        assert_eq!(steamroll_array(&arr), vec![1, 3, 4]);
    }
}
