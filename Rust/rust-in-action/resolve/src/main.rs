use std::{
    net::{SocketAddr, UdpSocket},
    time::Duration,
    vec,
};

use clap::{Arg, Command};
use hickory_proto::{
    op::{Message, MessageType, OpCode, Query},
    rr::{Name, RecordType},
    serialize::binary::{BinEncodable, BinEncoder},
};

fn main() {
    let matches = Command::new("resolve")
        .about("A simple to use DNS resolver")
        .arg(
            Arg::new("dns-server")
                .short('s')
                .long("server")
                .default_value("1.1.1.1"),
        )
        .arg(Arg::new("domain-name").required(true))
        .get_matches();

    let domain_name_raw = matches.get_one::<String>("domain-name").unwrap();
    let domain_name = Name::from_ascii(&domain_name_raw).unwrap();

    let dns_server_raw = matches.get_one::<String>("dns-server").unwrap();
    let dns_server: SocketAddr = format!("{}:53", dns_server_raw)
        .parse()
        .expect("invalid address");

    let mut request_as_bytes: Vec<u8> = Vec::with_capacity(512);
    let mut response_as_bytes: Vec<u8> = vec![0; 512];

    let mut msg = Message::new();
    msg.set_id(rand::random::<u16>())
        .set_message_type(MessageType::Query)
        .add_query(Query::query(domain_name, RecordType::A))
        .set_op_code(OpCode::Query)
        .set_recursion_desired(true);

    let mut encoder = BinEncoder::new(&mut request_as_bytes);
    msg.emit(&mut encoder).unwrap();

    let localhost = UdpSocket::bind("0.0.0.0:0").expect("cannot bind to local socket");
    let timeout = Duration::from_secs(3);
    localhost.set_read_timeout(Some(timeout)).unwrap();
    localhost.set_nonblocking(false).unwrap();

    let _amt = localhost
        .send_to(&request_as_bytes, dns_server)
        .expect("socket misconfigured");

    let (_amt, _remote) = localhost
        .recv_from(&mut response_as_bytes)
        .expect("timeout reached");

    let dns_message = Message::from_vec(&response_as_bytes).expect("unable to parse response");

    for answer in dns_message.answers() {
        if answer.record_type() == RecordType::A {
            let resource = answer.clone().into_data();
            let ip = resource.ip_addr().expect("invalid IP address received");
            println!("{}", ip.to_string());
        }
    }
}
