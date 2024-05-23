mod api;
mod command;
mod error;
mod models;

use command::{
    create_new_gist, get_commits_to_repository, get_gist_content, get_gists_for_authenticated_user,
    get_public_gists, get_public_repositories, get_repositories_for_authenticated_user,
    get_users_associated_with_repository,
};

fn main() {
    tauri::Builder::default()
        .invoke_handler(tauri::generate_handler![
            create_new_gist,
            get_public_gists,
            get_public_repositories,
            get_repositories_for_authenticated_user,
            get_gists_for_authenticated_user,
            get_gist_content,
            get_users_associated_with_repository,
            get_commits_to_repository
        ])
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}
