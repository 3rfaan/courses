use crate::api::{make_get_request, make_post_request};
use crate::models::{
    APIResult, Commit, Gist, GistInput, GithubUser, NewGistResponse, Repository, URL,
};

#[tauri::command]
pub fn get_public_gists() -> APIResult<Vec<Gist>> {
    let res = make_get_request(URL::WithBaseUrl("gists"), None)?;
    let res = serde_json::from_str(&res).unwrap();
    Ok(res)
}

#[tauri::command]
pub fn get_public_repositories() -> APIResult<Vec<Repository>> {
    let res = make_get_request(URL::WithBaseUrl("repositories"), None)?;
    let res = serde_json::from_str(&res).unwrap();
    Ok(res)
}

#[tauri::command]
pub fn get_repositories_for_authenticated_user(token: &str) -> APIResult<Vec<Repository>> {
    let res = make_get_request(URL::WithBaseUrl("user/repos?type=private"), Some(token))?;
    let res = serde_json::from_str(&res).unwrap();
    Ok(res)
}

#[tauri::command]
pub fn get_gists_for_authenticated_user(token: &str) -> APIResult<Vec<Gist>> {
    let res = make_get_request(URL::WithBaseUrl("gists"), Some(token))?;
    let res = serde_json::from_str(&res).unwrap();
    Ok(res)
}

#[tauri::command]
pub fn get_gist_content(url: String, token: Option<&str>) -> APIResult<String> {
    let res = make_get_request(URL::WithoutBaseUrl(url), token)?;
    Ok(res)
}

#[tauri::command]
pub fn get_users_associated_with_repository(
    url: String,
    token: Option<&str>,
) -> APIResult<Vec<GithubUser>> {
    let res = make_get_request(URL::WithoutBaseUrl(url), token)?;
    let res = serde_json::from_str(&res).unwrap();
    Ok(res)
}

#[tauri::command]
pub fn get_commits_to_repository(url: String, token: Option<&str>) -> APIResult<Vec<Commit>> {
    let res = make_get_request(URL::WithoutBaseUrl(url), token)?;
    let res = serde_json::from_str(&res).unwrap();
    Ok(res)
}

#[tauri::command]
pub fn create_new_gist(gist: GistInput, token: &str) -> APIResult<NewGistResponse> {
    let res = make_post_request(URL::WithBaseUrl("gists"), Some(token), gist)?;
    let res = serde_json::from_str(&res).unwrap();
    Ok(res)
}
