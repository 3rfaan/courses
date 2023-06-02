/* Fill in the blank */
fn main() {
    let mut values = vec![1, 2, 3];
    let mut values_iter = values.iter_mut();

    if let Some(v) = values_iter.next() {
        *v = 0;
    }

    assert_eq!(values, vec![0, 2, 3]);
}
