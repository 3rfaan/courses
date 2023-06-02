use std::fmt;

struct Structure(i32);

struct Deep(Structure);

impl fmt::Debug for Deep {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{}", self.0 .0)
    }
}

fn main() {
    // The problem with `derive` is there is no control over how
    // the results look. What if I want this to just show a `7`?

    /* Make it print: Now 7 will print! */
    println!("Now {:?} will print!", Deep(Structure(7)));
}
