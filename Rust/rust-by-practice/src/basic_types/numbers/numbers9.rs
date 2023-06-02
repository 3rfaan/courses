fn main() {
    let mut sum = 0;
    for i in -3..2 {
        sum += i
    }

    println!("sum = {}", sum); // -5

    assert!(sum == -5);

    for c in 'a'..='z' {
        println!("{}", c as u32);
    }
}
