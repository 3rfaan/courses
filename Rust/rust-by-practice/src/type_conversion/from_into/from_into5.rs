#[derive(Debug, PartialEq)]
struct EvenNum(i32);

impl TryFrom<i32> for EvenNum {
    type Error = ();

    // IMPLEMENT `try_from`
    fn try_from(value: i32) -> Result<Self, Self::Error> {
        if value % 2 == 0 {
            Ok(EvenNum(value))
        } else {
            Err(())
        }
    }
}

fn main() {
    assert_eq!(EvenNum::try_from(8), Ok(EvenNum(8)));
    assert_eq!(EvenNum::try_from(5), Err(()));

    // FILL in the blanks
    let result: Result<EvenNum, ()> = 8i32.try_into();
    assert_eq!(result, Ok(EvenNum(8)));
    let result: Result<EvenNum, ()> = 5i32.try_into();
    assert_eq!(result, Err(()));

    println!("Success!");
}
