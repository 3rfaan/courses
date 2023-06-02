#![allow(incomplete_features)]
#![feature(generic_const_exprs)]

fn check_size<T>(val: T)
where
    Assert<{ core::mem::size_of::<T>() < 768 }>: IsTrue,
{
    //...
}

// Fix the errors in main.
fn main() {
    check_size([0u8; 767]);
    check_size([0i32; 191]);
    check_size(["hello你好"; 11]); // Size of &str ?
    check_size([(); 0].map(|_| "hello你好".to_string())); // Size of String?
    check_size(['中'; 3]); // Size of char ?

    println!("Success!");
}

pub enum Assert<const CHECK: bool> {}

pub trait IsTrue {}

impl IsTrue for Assert<true> {}
