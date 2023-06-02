fn main() {
    let arr: [u8; 3] = [1, 2, 3];

    let v = Vec::from(arr);
    is_vec(&v);

    let v = vec![1, 2, 3];
    is_vec(&v);

    // vec!(..) and vec![..] are same macros, so
    let v = vec![1, 2, 3];
    is_vec(&v);

    // In code below, v is Vec<[u8; 3]> , not Vec<u8>
    // USE Vec::new and `for` to rewrite the below code
    let mut v1 = vec![];

    for i in &v {
        v1.push(*i);
    }
    is_vec(&v1);

    assert_eq!(v, v1);

    println!("Success!");
}

fn is_vec(v: &Vec<u8>) {}
