enum MyEnum {
    Foo,
    Bar,
}

fn main() {
    let mut count = 0;

    let v = vec![MyEnum::Foo, MyEnum::Bar, MyEnum::Foo];
    for e in v {
        if matches!(e, MyEnum::Foo) {
            // Fix the error by changing only this line
            count += 1;
        }
    }

    assert_eq!(count, 2);

    println!("Success!");
}
