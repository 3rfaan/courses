use rand::RngCore;
use std::fmt::Display;

#[derive(Debug)]
struct MacAddress([u8; 6]);

impl Display for MacAddress {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let octet = &self.0;
        write!(
            f,
            "{:02x}:{:02x}:{:02x}:{:02x}:{:02x}:{:02x}",
            octet[0], octet[1], octet[2], octet[3], octet[4], octet[5]
        )
    }
}

impl MacAddress {
    fn new() -> Self {
        let mut octets: [u8; 6] = [0; 6];
        rand::rng().fill_bytes(&mut octets);
        octets[0] |= 0b0000_0011; // Sets MAC address to local and unicast
        Self(octets)
    }

    fn is_local(&self) -> bool {
        (self.0[0] & 0b0000_0010) == 0b0000_0010
    }

    fn is_unicast(&self) -> bool {
        (self.0[0] & 0b0000_0001) == 0b0000_0001
    }
}

fn main() {
    let mac = MacAddress::new();
    assert!(mac.is_local());
    assert!(mac.is_unicast());
    println!("mac: {}", mac);
}
