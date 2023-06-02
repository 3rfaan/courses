/* Make it work
- Dont use `_reborrow` and `_count_reborrowed`
- Dont modify `assert_eq`
*/
fn main() {
    let mut count = 0;

    let mut inc = move || {
        // Move, so closure takes ownership instead of mutable borrow
        count += 1;
        println!("`count`: {}", count);
    };

    inc();

    let _reborrow = &count; // count implements Copy trait, so the moved value of count got copied
                            // and count is still accessible

    inc();

    // The closure no longer needs to borrow `&mut count`. Therefore, it is
    // possible to reborrow without an error
    let _count_reborrowed = &mut count;

    assert_eq!(count, 0);
}
