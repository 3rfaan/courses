// Fix the errors without adding or removing lines
fn main() {
    let names = [String::from("liming"), String::from("hanmeimei")];
    for name in &names { // or: names.clone() / names.as_ref()
         // Do something with name...
    }

    println!("{:?}", names);

    let numbers = [1, 2, 3];
    // The elements in numbers are Copy，so there is no move here
    for n in numbers {
        // Do something with name...
    }

    println!("{:?}", numbers);
}
