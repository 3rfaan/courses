use dioxus::prelude::*;

#[component]
pub fn Favorites() -> Element {
    let mut resource = use_resource(crate::backend::list_dogs);
    let mut favorites = resource.suspend()?;

    rsx! {
        div {
            id: "favorites",
            div {
                id: "favorites-container",
                for (id, url) in favorites().unwrap() {
                    div {
                        key: "{id}",
                        class: "favorite-dog",
                        img { src: "{url}" }
                        button {
                            onclick: move |_| async move {
                                _ = crate::backend::delete_dog(id).await;
                                resource.restart();
                            },
                            "❌"
                        }
                    }
                }
            }
        }
    }
}
