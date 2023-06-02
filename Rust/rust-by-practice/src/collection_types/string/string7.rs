// FILL in the blanks
use std::mem;

fn main() {
    let story = String::from("Rust By Practice");

    // Prevent automatically dropping of the String's data
    let mut story = mem::ManuallyDrop::new(story);

    let ptr = story.as_mut_ptr();
    let len = story.len();
    let capacity = story.capacity();

    assert_eq!(16, len);

    // We can rebuild a String out of ptr, len, and capacity. This is all
    // unsafe because we are responsible for making sure the components are
    // valid:
    let s = unsafe { String::from_raw_parts(ptr, len, capacity) };

    assert_eq!(*story, s);

    println!("Success!");
}
