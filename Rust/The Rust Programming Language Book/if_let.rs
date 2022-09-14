let config_max = Some(3u8);

match config_max {
  Some(max) => println!("The maximum is configured to be {}", max),
  _ => (),
}

// Better:

let config_max = Some(3u8);

if let Some(max) = config_max {
  println!("The maximum is configured to be {}", max);
}

// --- //

let mut count = 0;

if let Coin::Quarter(state) = coin {
  println!("State quarter from {:?}!", state);
} else {
  count += 1;
}