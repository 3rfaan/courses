// MAKE the code work by fixing all panics
fn main() {
    assert_eq!("abc".as_bytes(), [97, 98, 99]); // a = 97

    let v = vec![1, 2, 3];
    let ele = v[2]; // last index: 2
                    // unwrap may panic when get return a None
    let ele = v.get(2).unwrap();

    // Sometimes, the compiler is unable to find the overflow errors for you in compile time, so a panic will occur
    let v = production_rate_per_hour(2);

    // because of the same reason as above, we have to wrap it in a function to make the panic occur
    divide(15, 1);

    println!("Success!")
}

fn divide(x: u8, y: u8) {
    println!("{}", x / y)
}

fn production_rate_per_hour(speed: u64) -> f64 {
    // change u8 to u64 because u8 will overflow when multiplying
    let cph: u64 = 221;
    match speed {
        1..=4 => (speed * cph) as f64,
        5..=8 => (speed * cph) as f64 * 0.9,
        9..=10 => (speed * cph) as f64 * 0.77,
        _ => 0 as f64,
    }
}

pub fn working_items_per_minute(speed: u64) -> u32 {
    // change u8 to u64
    (production_rate_per_hour(speed) / 60 as f64) as u32
}
