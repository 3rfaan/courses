use reqwest;
use std::error::Error;

#[tokio::main]
async fn main() -> Result<(), Box<dyn Error>> {
    let url = "http://www.rustinaction.com/";
    let response = reqwest::get(url).await?;

    let content = response.text().await?;
    print!("{}", content);

    Ok(())
}
