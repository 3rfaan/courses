trait IpAddr {
    fn display(&self);
}

struct V4(String);
impl IpAddr for V4 {
    fn display(&self) {
        println!("ipv4: {:?}", self.0)
    }
}
struct V6(String);
impl IpAddr for V6 {
    fn display(&self) {
        println!("ipv6: {:?}", self.0)
    }
}

fn main() {
    // FILL in the blank
    let v: Vec<Box<dyn IpAddr>> = vec![
        Box::new(V4("127.0.0.1".to_string())),
        Box::new(V6("::1".to_string())),
    ];

    for ip in v {
        ip.display();
    }
}
