trait Person {
    fn name(&self) -> String;
}

// Person is a supertrait of Student.
// Implementing Student requires you to also impl Person.
trait Student: Person {
    fn university(&self) -> String;
}

trait Programmer {
    fn fav_language(&self) -> String;
}

// CompSciStudent (computer science student) is a subtrait of both Programmer
// and Student. Implementing CompSciStudent requires you to impl both supertraits.
trait CompSciStudent: Programmer + Student {
    fn git_username(&self) -> String;
}

fn comp_sci_student_greeting(student: &dyn CompSciStudent) -> String {
    format!(
        "My name is {} and I attend {}. My favorite language is {}. My Git username is {}",
        student.name(),
        student.university(),
        student.fav_language(),
        student.git_username()
    )
}

struct CSStudent {
    name: String,
    university: String,
    fav_language: String,
    git_username: String,
}

// IMPLEMENT the necessary traits for CSStudent to make the code work
impl Person for CSStudent {
    fn name(&self) -> String {
        self.name.clone()
    }
}

impl Student for CSStudent {
    fn university(&self) -> String {
        self.university.clone()
    }
}

impl Programmer for CSStudent {
    fn fav_language(&self) -> String {
        self.fav_language.clone()
    }
}

impl CompSciStudent for CSStudent {
    fn git_username(&self) -> String {
        self.git_username.clone()
    }
}

fn main() {
    let student = CSStudent {
        name: "Sunfei".to_string(),
        university: "XXX".to_string(),
        fav_language: "Rust".to_string(),
        git_username: "sunface".to_string(),
    };

    // FILL in the blank
    println!("{}", comp_sci_student_greeting(&student));
}
