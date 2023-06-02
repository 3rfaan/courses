/* Make it work by adding proper lifetime annotations */
struct ImportantExcerpt {
    part: &'static str,
}

impl ImportantExcerpt {
    fn level(&self) -> i32 {
        3
    }
}

fn main() {}
