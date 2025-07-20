#[cfg(windows)]
use kernel32;

#[cfg(windows)]
use winapi;

#[cfg(not(windows))]
use libc;

use chrono::{DateTime, Local, TimeZone};
use clap::{Command, arg, command};
use std::mem::zeroed;

struct Clock;

impl Clock {
    fn get() -> DateTime<Local> {
        Local::now()
    }

    #[cfg(windows)]
    fn set<Tz: TimeZone>(t: DateTime<Tz>) -> () {
        use chrono::Weekday;
        use kernel32::SetSystemTime;
        use winapi::{SYSTEMTIME, WORD};

        let t = t.with_timezone(&Local);

        let mut systime: SYSTEMTIME = unsafe { zeroed() };

        let dow = match t.weekday() {
            Weekday::Mon => 1,
            Weekday::Tue => 2,
            Weekday::Wed => 3,
            Weekday::Thu => 4,
            Weekday::Fri => 5,
            Weekday::Sat => 6,
            Weekday::Sun => 7,
        };

        let mut ns = t.nanosecond();
        let is_leap_second = ns > 1_000_000_000;

        if is_leap_second {
            ns -= 1_000_000_000;
        }

        systime.wYear = t.year() as WORD;
        systime.wMonth = t.month as WORD;
        systime.wDayOfWeek = dow as WORD;
        systime.wDay = t.day() as WORD;
        systime.wHour = t.hour() as WORD;
        systime.wSecond = t.second() as WORD;
        systime.wMilliseconds = (ns / 1_000_000) as WORD;

        let systime_ptr = &systime as *const SYSTEMTIME;

        unsafe {
            SetSystemTime(systime_ptr);
        }
    }

    #[cfg(not(windows))]
    fn set<Tz: TimeZone>(t: DateTime<Tz>) -> () {
        use libc::{settimeofday, timezone};
        use libc::{suseconds_t, time_t, timeval};

        let t = t.with_timezone(&Local);
        let mut u: timeval = unsafe { zeroed() };

        u.tv_sec = t.timestamp() as time_t;
        u.tv_usec = t.timestamp_subsec_micros() as suseconds_t;

        unsafe {
            let mock_tz: *const timezone = std::ptr::null();
            settimeofday(&u as *const timeval, mock_tz);
        }
    }
}

fn main() {
    let matches = command!()
        .arg(
            arg!(-s --standard <FORMAT> "Output format standard")
                .value_parser(["rfc2822", "rfc3339", "timestamp"])
                .default_value("rfc3339"),
        )
        .subcommand(Command::new("get").about("Get the current time"))
        .subcommand(
            Command::new("set")
                .about("Set the current time")
                .arg(arg!(<datetime> "Datetime to set the system clock to").required(true)),
        )
        .get_matches();

    let action = match matches.subcommand() {
        Some(("get", _)) => "get",
        Some(("set", _)) => "set",
        None => "get",
        _ => panic!("Unexpected subcommand"),
    };
    let std = matches.get_one::<String>("standard").unwrap();

    if action == "set" {
        let t_ = match matches.subcommand() {
            Some(("set", sub_m)) => sub_m.get_one::<String>("datetime").unwrap(),
            _ => unreachable!(),
        };

        let parser = match std.as_str() {
            "rfc2822" => DateTime::parse_from_rfc2822,
            "rfc3339" => DateTime::parse_from_rfc3339,
            _ => unimplemented!(),
        };

        let err_msg = format!("Unable to parse {} according to {}", t_, std);
        let t = parser(t_).expect(&err_msg);

        Clock::set(t)
    }

    let now = Clock::get();
    match std.as_str() {
        "timestamp" => println!("{}", now.timestamp()),
        "rfc2822" => println!("{}", now.to_rfc2822()),
        "rfc3339" => println!("{}", now.to_rfc3339()),
        _ => unreachable!(),
    }
}
