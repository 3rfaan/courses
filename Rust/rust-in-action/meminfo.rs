use std::fs::File;
use std::io::{BufRead, BufReader};

fn main() {
    let pid = std::process::id();
    println!("Current PID: {}", pid);

    let file = File::open("/proc/self/maps").expect("Failed to open /proc/self/maps");
    let reader = BufReader::new(file);

    for line in reader.lines() {
        if let Ok(line) = line {
            println!("{}", line);
        }
    }
}
