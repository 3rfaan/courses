struct Array<T, const N: usize> {
    data: [T; N],
}

fn main() {
    let arrays: [Array<i32, 3>; 3] = [
        Array { data: [1, 2, 3] },
        Array { data: [5, 6, 7] },
        Array { data: [8, 9, 10] },
    ];

    let others: [Array<f64, 2>; 4] = [
        Array { data: [1.0, 2.0] },
        Array { data: [3.0, 4.0] },
        Array { data: [5.0, 6.0] },
        Array { data: [7.0, 8.0] },
    ];

    println!("Success!");
}
