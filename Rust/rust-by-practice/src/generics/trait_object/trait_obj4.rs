trait Foo {
    fn method(&self) -> String;
}

impl Foo for u8 {
    fn method(&self) -> String {
        format!("u8: {}", *self)
    }
}

impl Foo for String {
    fn method(&self) -> String {
        format!("string: {}", *self)
    }
}

// IMPLEMENT below with generics.
fn static_dispatch<T: Foo>(a: T) {
    // or: fn static_dispatch(a: impl Foo)
    a.method();
}

// Implement below with trait objects.
fn dynamic_dispatch(a: &dyn Foo) {
    a.method();
}

fn main() {
    let x = 5u8;
    let y = "Hello".to_string();

    static_dispatch(x);
    dynamic_dispatch(&y);

    println!("Success!");
}
