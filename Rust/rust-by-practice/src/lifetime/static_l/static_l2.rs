#[derive(Debug)]
struct Config {
    a: String,
    b: String,
}
static mut config: Option<&mut Config> = None;

/* Make it work without changing the function signatures of `init`*/
fn init() -> Option<&'static mut Config> {
    let boxed = Box::new(Config {
        a: "A".to_string(),
        b: "B".to_string(),
    });

    Some(Box::leak(boxed))
}

fn main() {
    unsafe {
        config = init();

        println!("{:?}", config)
    }
}
