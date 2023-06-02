// Add generic for Val to make the code work, DON'T modify the code in `main`.
struct Val<T> {
    val: T,
}

impl<T> Val<T> {
    fn value(&self) -> &T {
        &self.val
    }
}

fn main() {
    let x = Val { val: 3.0 };
    let y = Val {
        val: "hello".to_string(),
    };
    println!("{:.1}, {}", x.value(), y.value());

    // Check type
    type_of(&x);
    type_of(&y);
}

fn type_of<T>(_: &T) {
    println!("{}", std::any::type_name::<T>())
}
