use std::collections::HashMap;

fn main() {
    let mut h: HashMap<char, Vec<usize>> = HashMap::new();

    for (i, c) in "hello!".chars().enumerate() {
        h.entry(c).or_insert(Vec::new()).push(i);
    }

    let mut sum = 0;

    for i in h.get(&'l').unwrap() {
        sum += *i;
    }

    println!("{}", sum);
}
