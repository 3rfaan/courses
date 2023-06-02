fn get_person() -> String {
    String::from("sunface")
}

fn get_format() -> (usize, usize) {
    (4, 1)
}

fn main() {
    let person = get_person();
    println!("Hello, {person}!");

    let (width, precision) = get_format();
    let scores = [("sunface", 99.12), ("jack", 60.34)];
    /* Make it print:
    sunface:   99.1
    jack:   60.3
    */
    for (name, score) in scores {
        println!("{name}: {score}");
    }
}
