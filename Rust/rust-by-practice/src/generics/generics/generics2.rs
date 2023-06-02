// Implement the generic function below.
fn sum<T>(a: T, b: T) -> T
where
    T: std::ops::Add<Output = T>,
{
    a + b
}

fn main() {
    assert_eq!(5, sum::<i8>(2i8, 3i8));
    assert_eq!(50, sum::<i32>(20, 30));
    assert_eq!(2.46, sum::<f64>(1.23, 1.23));

    println!("Success!");
}
