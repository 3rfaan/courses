# Cargo

- We can create a project using `cargo new`.
- We can build a project using `cargo build`.
- We can build and run a project in one step using `cargo run`.
- We can build a project without producing a binary to check for errors using `cargo check`.
- Instead of saving the result of the build in the same directory as our code, Cargo stores it in the _target/debug_ directory.

## Building for Release

When your project is finally ready for release, you can use `cargo build --release` to compile it with optimizations. This command will create an executable in _target/release_ instead of _target/debug_.

## Summary

You’re already off to a great start on your Rust journey! In this chapter, you’ve learned how to:

Install the latest stable version of Rust using `rustup`
Update to a newer Rust version
Open locally installed documentation
Write and run a “Hello, world!” program using `rustc` directly
Create and run a new project using the conventions of Cargo
