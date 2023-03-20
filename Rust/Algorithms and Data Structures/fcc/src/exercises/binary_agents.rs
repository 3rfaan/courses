// Return an English translated sentence of the passed binary string.

// The binary string will be space separated.

#[allow(dead_code)]
fn binary_agent(s: &str) -> String {
    let mut result = String::new();

    // Splitting string of binary digits into a vector where each element holds one byte, then
    // mapping over each byte and converting from base 2 to u8
    for byte in s.split(' ').map(|x| u8::from_str_radix(x, 2).unwrap()) {
        // Typecasting the u8 value in byte to char (ASCII) and pushing it to the result string
        // which will hold the sentence in readable ASCII format
        result.push(byte as char);
    }
    result
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        assert_eq!(binary_agent("01000001 01110010 01100101 01101110 00100111 01110100 00100000 01100010 01101111 01101110 01100110 01101001 01110010 01100101 01110011 00100000 01100110 01110101 01101110 00100001 00111111"), "Aren't bonfires fun!?");
    }

    #[test]
    fn test2() {
        assert_eq!(binary_agent("01001001 00100000 01101100 01101111 01110110 01100101 00100000 01000110 01110010 01100101 01100101 01000011 01101111 01100100 01100101 01000011 01100001 01101101 01110000 00100001"), "I love FreeCodeCamp!");
    }
}
