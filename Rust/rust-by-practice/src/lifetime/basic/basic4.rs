// `'a` must live longer than the function.
// Here, `&String::from("foo")` would create a `String`, followed by a
// reference. Then the data is dropped upon exiting the scope, leaving
// a reference to invalid data to be returned.

/* Fix the error in three ways  */
fn invalid_output() -> String {
    String::from("foo")
}

fn main() {}

// or:
//
//fn invalid_output() -> &'static str {
//    "foo"
//}
//
//fn main() {}
//
// or:
//
//fn valid_output<'a>(s: &'a String) -> &'a String {
//    s
//}
//
//fn main() {
//    let s = String::from("foo");
//    let output = valid_output(&s);
//
//    println!("{}", output);
//}
