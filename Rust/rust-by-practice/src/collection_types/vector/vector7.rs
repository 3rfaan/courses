#[derive(Debug, PartialEq)]
enum IpAddr {
    V4(String),
    V6(String),
}
fn main() {
    // FILL in the blank
    let ip_v4: String = String::from("127.0.0.1");
    let ip_v6: String = String::from("::1");
    let v: Vec<IpAddr> = vec![IpAddr::V4(ip_v4), IpAddr::V6(ip_v6)];

    // Comparing two enums need to derive the PartialEq trait
    assert_eq!(v[0], IpAddr::V4("127.0.0.1".to_string()));
    assert_eq!(v[1], IpAddr::V6("::1".to_string()));

    println!("Success!");
}
