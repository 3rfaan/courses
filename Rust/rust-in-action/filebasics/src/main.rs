//! Simulating files one step at a time.

/// Represent a "file",
/// which probably lives on a file system.
#[derive(Debug)]
pub struct File {
    name: String,
    data: Vec<u8>,
}

impl File {
    /// Creates a new, empty `File`
    ///
    /// # Examples
    ///
    /// ```
    /// let f = File::new("file_name.txt");
    /// ```
    pub fn new(name: &str) -> Self {
        Self {
            name: String::from(name),
            data: Vec::new(),
        }
    }

    /// Returns the file's length in bytes.
    pub fn len(&self) -> usize {
        self.data.len()
    }

    /// Returns the file's name.
    pub fn name(&self) -> String {
        self.name.clone()
    }
}

fn main() {
    let f1 = File::new("f1.txt");

    let (name, len) = (f1.name(), f1.len());

    println!("{:?}", f1);
    println!("{} is {} bytes long", name, len);
}
