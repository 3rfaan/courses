use clap::{Parser, Subcommand};
use reqwest::header::{HeaderMap, HeaderName, HeaderValue};

#[derive(Parser)]
#[command(name = "httpc")]
#[command(about = "A simple HTTP client", long_about = None)]
struct Cli {
    #[command(subcommand)]
    command: Commands,
}

#[derive(Subcommand)]
enum Commands {
    Get {
        #[arg(help = "The URL to request")]
        url: String,

        #[arg(short = 'H', long = "header", help = "Add headers", num_args = 0..)]
        headers: Vec<String>,
    },
    Post {
        #[arg(help = "The URL to request")]
        url: String,

        #[arg(short, long, help = "JSON body")]
        body: Option<String>,

        #[arg(short = 'H', long = "header", help = "Add headers", num_args = 0..)]
        headers: Vec<String>,
    },
}

#[tokio::main]
async fn main() {
    let cli = Cli::parse();

    match cli.command {
        Commands::Get { url, headers } => {
            let client = reqwest::Client::new();
            let res = client
                .get(&url)
                .headers(parse_headers(&headers))
                .send()
                .await
                .unwrap();
            let txt = res.text().await.unwrap();
            println!("{txt}");
        }
        Commands::Post { url, body, headers } => {
            let client = reqwest::Client::new();
            let res = client
                .post(&url)
                .headers(parse_headers(&headers))
                .json(
                    &serde_json::from_str::<serde_json::Value>(&body.unwrap_or("{}".into()))
                        .unwrap(),
                )
                .send()
                .await
                .unwrap();
            let txt = res.text().await.unwrap();
            println!("{txt}");
        }
    }
}

fn parse_headers(header_strings: &[String]) -> HeaderMap {
    let mut headers = HeaderMap::new();

    for h in header_strings {
        if let Some((key, val)) = h.split_once(':') {
            if let (Ok(name), Ok(val)) = (
                HeaderName::from_bytes(key.trim().as_bytes()),
                HeaderValue::from_str(val.trim()),
            ) {
                headers.insert(name, val);
            }
        }
    }
    headers
}
