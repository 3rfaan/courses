use std::collections::HashMap;

use crate::error::TauriError;
use serde::{Deserialize, Serialize};

pub type APIResult<T, E = TauriError> = Result<T, E>;

#[derive(Deserialize, Serialize)]
pub struct Commit {
    commit: Option<CommitNode>,
}

#[derive(Deserialize, Serialize)]
struct CommitNode {
    message: String,
}

#[derive(Deserialize, Serialize)]
pub struct Gist {
    id: String,
    description: Option<String>,
    owner: GithubUser,
    files: HashMap<String, GistFile>,
    public: bool,
}

#[derive(Deserialize, Serialize)]
struct GistContent {
    content: String,
}

#[derive(Deserialize, Serialize)]
pub struct GistInput {
    description: Option<String>,
    files: HashMap<String, GistContent>,
    public: bool,
}

#[derive(Deserialize, Serialize)]
struct GistFile {
    filename: String,
    language: Option<String>,
    raw_url: String,
}

#[derive(Deserialize, Serialize)]
pub struct GithubUser {
    login: String,
    avatar_url: Option<String>,
}

#[derive(Deserialize, Serialize)]
pub struct NewGistResponse {
    id: String,
}

#[derive(Deserialize, Serialize)]
pub struct Repository {
    id: i32,
    name: String,
    description: Option<String>,
    owner: GithubUser,
    stargazers_url: String,
    commits_url: String,
    contributors_url: String,
}

pub enum URL {
    WithBaseUrl(&'static str),
    WithoutBaseUrl(String),
}

impl URL {
    pub fn value(self) -> String {
        match self {
            URL::WithBaseUrl(url) => format!("https://api.github.com/{url}"),
            URL::WithoutBaseUrl(url) => url,
        }
    }
}
