pub use crate::front_of_house::hosting;

pub mod back_of_house;
pub mod front_of_house;

pub fn eat_at_restaurant() -> String {
    front_of_house::hosting::add_to_waitlist();

    back_of_house::cook_order();

    String::from("yummy, yummy")
}
