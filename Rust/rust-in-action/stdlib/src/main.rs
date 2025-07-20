use std::io::prelude::*;
use std::net::TcpStream;

fn main() -> std::io::Result<()> {
    let host = "www.rustinaction.com:80";

    let mut conn = TcpStream::connect(host)?;

    conn.write_all(b"GET / HTTP/1.0")?;
    conn.write_all(b"\r\n")?; // newline

    conn.write_all(b"Host: www.rustinaction.com")?;
    conn.write_all(b"\r\n\r\n")?; // two newlines means end-of-request

    std::io::copy(&mut conn, &mut std::io::stdout())?;

    Ok(())
}
