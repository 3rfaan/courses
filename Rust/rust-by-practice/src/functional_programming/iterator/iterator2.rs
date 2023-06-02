/* Fill in the blank */
fn main() {
    let mut v = Vec::new();
    for n in 0..100 {
        v.push(n);
    }

    assert_eq!(v.len(), 100);
}
