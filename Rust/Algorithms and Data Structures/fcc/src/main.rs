use cli_table::{print_stdout, Cell, Style, Table};
use colored::*;
use std::io::{self, Write};
use std::{collections::BTreeMap, error::Error, process::Command};

pub mod exercises;

fn main() -> Result<(), Box<dyn Error>> {
    let exercises = BTreeMap::from([
        (1, "sum_all_numbers_in_range"),
        (2, "diff_two_arrays"),
        (3, "seek_and_destroy"),
        (4, "wherefore_art_thou"),
        (5, "spinal_tab_case"),
        (6, "pig_latin"),
        (7, "search_and_replace"),
        (8, "dna_pairing"),
        (9, "missing_letters"),
        (10, "sorted_union"),
        (11, "convert_html_entities"),
        (12, "sum_odd_fibonacci_numbers"),
        (13, "sum_all_primes"),
        (14, "smallest_common_multiple"),
        (15, "drop_it"),
        (16, "steamroller"),
        (17, "binary_agents"),
        (18, "everything_be_true"),
        (19, "arguments_optional"),
        (20, "make_a_person"),
        (21, "map_the_debris"),
    ]);

    println!(
        "{}\n{}\n{}\n{}\n{}",
        "========================================================="
            .bold()
            .yellow(),
        "WELCOME TO THE RUST ALGORITHMS AND DATA STRUCTURES COURSE"
            .bold()
            .yellow(),
        "Author: Arfan Zubi".bold().black(),
        "License: GNU General Public License 3".bold().black(),
        "========================================================="
            .bold()
            .yellow(),
    );

    let mut table = vec![];

    for (k, v) in &exercises {
        table.push(vec![k.cell(), v.cell()]);
    }

    print_stdout(
        table
            .table()
            .title(vec!["No".cell().bold(true), "Exercise".cell().bold(true)])
            .bold(true),
    )?;

    loop {
        let mut exc = String::new();

        print!(
            "===> {} ({}): ",
            "Enter number of exercise".bold(),
            "To quit type 0".yellow()
        );
        io::stdout().flush()?;
        io::stdin().read_line(&mut exc)?;

        if exc.trim() == "all".to_string() {
            let output = Command::new("cargo").arg("test").output()?;

            io::stdout().write_all(&output.stdout)?;
        }

        let exc = match exc.trim().parse() {
            Ok(e) => {
                if e >= 0 && e <= exercises.len() as i32 {
                    e
                } else {
                    -1
                }
            }
            Err(_) => -1,
        };

        if exc == 0 {
            break;
        } else if exc == -1 {
            println!(
                "{}",
                "Please enter the number of the exercise (1 - 21)"
                    .bold()
                    .red()
            );
            continue;
        }

        let output = Command::new("cargo")
            .arg("test")
            .arg("--")
            .arg(exercises.get(&exc).expect("Exercise not found"))
            .output()?;

        io::stdout().write_all(&output.stdout)?;
        //io::stderr().write_all(&output.stderr)?;
    }

    Ok(())
}
