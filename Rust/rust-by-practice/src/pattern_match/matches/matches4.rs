fn main() {
    let alphabets = ['a', 'E', 'Z', '0', 'x', '9', 'Y'];

    // Fill the blank with `matches!` to make the code work
    for ab in alphabets {
        assert!(matches!(ab, 'A'..='Z' | 'a'..='z' | '0'..='9'));
    }

    println!("Success!");
}
