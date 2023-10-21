use bevy::{math::*, prelude::*, sprite::collide_aabb::*};
use rand::prelude::*;

//paddle
const PADDLE_START_Y: f32 = BOTTOM_WALL + 60.;
const PADDLE_SIZE: Vec2 = Vec2::new(120.0, 20.0);
const PADDLE_COLOR: Color = Color::rgb(0.3, 0.3, 0.7);
const PADDLE_SPEED: f32 = 500.0;

//ball
const BALL_COLOR: Color = Color::rgb(1.0, 0.5, 0.5);
const BALL_STARTING_POSITION: Vec3 = Vec3::new(0.0, -50.0, 1.0);
const BALL_SIZE: Vec2 = Vec2::new(30.0, 30.0);
const BALL_SPEED: f32 = 400.0;

//wall
const LEFT_WALL: f32 = -450.;
const RIGHT_WALL: f32 = 450.;
const BOTTOM_WALL: f32 = -300.;
const TOP_WALL: f32 = 300.;

const WALL_THICKNESS: f32 = 10.0;
const WALL_BLOCK_WIDTH: f32 = RIGHT_WALL - LEFT_WALL;
const WALL_BLOCK_HEIGHT: f32 = TOP_WALL - BOTTOM_WALL;
const WALL_COLOR: Color = Color::rgb(0.8, 0.8, 0.8);

//bricks
const BRICK_SIZE: Vec2 = Vec2::new(100., 30.);
const BRICK_COLOR: Color = Color::rgb(0.5, 0.5, 1.0);
const GAP_BETWEEN_PADDLE_AND_BRICKS: f32 = 270.0;
const GAP_BETWEEN_BRICKS: f32 = 5.0;
const GAP_BETWEEN_BRICKS_AND_CEILING: f32 = 20.0;
const GAP_BETWEEN_BRICKS_AND_SIDES: f32 = 20.0;

//scoreboard
const SCOREBOARD_FONT_SIZE: f32 = 40.0;
const SCOREBOARD_TEXT_PADDING: Val = Val::Px(5.0);
const TEXT_COLOR: Color = Color::rgb(0.5, 0.5, 1.0);
const SCORE_COLOR: Color = Color::rgb(1.0, 0.5, 0.5);

fn main() {
    App::new()
        .add_plugins(DefaultPlugins)
        .insert_resource(ClearColor(Color::rgb(0.9, 0.9, 0.9)))
        .insert_resource(Scoreboard { score: 0 })
        .add_systems(Update, (bevy::window::close_on_esc, update_scoreboard))
        .add_systems(Startup, setup)
        .add_systems(
            FixedUpdate,
            (
                move_paddle,
                apply_velocity,
                check_ball_collisions.after(apply_velocity),
            ),
        )
        .run();
}

#[derive(Component)]
struct Paddle;

#[derive(Component)]
struct Ball {
    size: Vec2,
}

#[derive(Component, Deref, DerefMut)]
struct Velocity(Vec2);

#[derive(Component)]
struct Collider {
    size: Vec2,
}

#[derive(Bundle)]
struct WallBundle {
    sprite_bundle: SpriteBundle,
    collider: Collider,
}

#[derive(Component)]
struct Brick;

#[derive(Resource, Clone, Copy)]
struct Scoreboard {
    score: usize,
}

#[derive(Resource, Default, Deref, DerefMut)]
struct CollisionSound(Handle<AudioSource>);

fn setup(mut commands: Commands, asset_server: Res<AssetServer>) {
    //camera
    commands.spawn(Camera2dBundle::default());

    //sound
    let ball_collision_sound = asset_server.load("sounds/breakout_collision.ogg");
    commands.insert_resource(CollisionSound(ball_collision_sound));

    //paddle
    commands.spawn((
        SpriteBundle {
            transform: Transform {
                translation: vec3(0., PADDLE_START_Y, 0.),
                ..default()
            },
            sprite: Sprite {
                color: PADDLE_COLOR,
                custom_size: Some(PADDLE_SIZE),
                ..default()
            },
            ..default()
        },
        Paddle,
        Collider { size: PADDLE_SIZE },
    ));

    //ball

    let ball_tex = asset_server.load("textures/circle.png");
    let mut rng = thread_rng();

    // Generate random initial direction
    let random_angle = rng.gen_range(0.0..std::f32::consts::TAU); // TAU is 2*PI
    let random_direction = Vec2::new(random_angle.cos(), random_angle.sin());

    commands.spawn((
        SpriteBundle {
            transform: Transform {
                translation: BALL_STARTING_POSITION,
                ..Default::default()
            },
            sprite: Sprite {
                color: BALL_COLOR,
                custom_size: Some(BALL_SIZE),
                ..Default::default()
            },
            texture: ball_tex,
            ..Default::default()
        },
        Ball { size: BALL_SIZE },
        Velocity(BALL_SPEED * random_direction),
    ));

    //walls
    {
        let vertical_wall_size = vec2(WALL_THICKNESS, WALL_BLOCK_HEIGHT + WALL_THICKNESS);
        let horizontal_wall_size = vec2(WALL_BLOCK_WIDTH + WALL_THICKNESS, WALL_THICKNESS);
        //left wall
        commands.spawn(WallBundle {
            sprite_bundle: SpriteBundle {
                transform: Transform {
                    translation: vec3(LEFT_WALL, 0.0, 0.0),
                    ..default()
                },
                sprite: Sprite {
                    color: WALL_COLOR,
                    custom_size: Some(vertical_wall_size),
                    ..default()
                },
                ..default()
            },
            collider: Collider {
                size: vertical_wall_size,
            },
        });

        //right wall
        commands.spawn(WallBundle {
            sprite_bundle: SpriteBundle {
                transform: Transform {
                    translation: vec3(RIGHT_WALL, 0.0, 0.0),
                    ..default()
                },
                sprite: Sprite {
                    color: WALL_COLOR,
                    custom_size: Some(vertical_wall_size),
                    ..default()
                },
                ..default()
            },
            collider: Collider {
                size: vertical_wall_size,
            },
        });

        //bottom wall
        commands.spawn(WallBundle {
            sprite_bundle: SpriteBundle {
                transform: Transform {
                    translation: vec3(0.0, BOTTOM_WALL, 0.0),
                    ..default()
                },
                sprite: Sprite {
                    color: WALL_COLOR,
                    custom_size: Some(horizontal_wall_size),
                    ..default()
                },
                ..default()
            },
            collider: Collider {
                size: horizontal_wall_size,
            },
        });

        //top wall
        commands.spawn(WallBundle {
            sprite_bundle: SpriteBundle {
                transform: Transform {
                    translation: vec3(0.0, TOP_WALL, 0.0),
                    ..default()
                },
                sprite: Sprite {
                    color: WALL_COLOR,
                    custom_size: Some(horizontal_wall_size),
                    ..default()
                },
                ..default()
            },
            collider: Collider {
                size: horizontal_wall_size,
            },
        });
    }

    //bricks
    {
        let offset_x = LEFT_WALL + GAP_BETWEEN_BRICKS_AND_SIDES + BRICK_SIZE.x * 0.5;
        let offset_y = BOTTOM_WALL + GAP_BETWEEN_PADDLE_AND_BRICKS + BRICK_SIZE.y * 0.5;

        let bricks_total_width = (RIGHT_WALL - LEFT_WALL) - 2. * GAP_BETWEEN_BRICKS_AND_SIDES;
        let bricks_total_height = (TOP_WALL - BOTTOM_WALL)
            - GAP_BETWEEN_BRICKS_AND_CEILING
            - GAP_BETWEEN_PADDLE_AND_BRICKS;

        let rows = (bricks_total_height / (BRICK_SIZE.y + GAP_BETWEEN_BRICKS)).floor() as i32;
        let columns = (bricks_total_width / (BRICK_SIZE.x + GAP_BETWEEN_BRICKS)).floor() as i32;

        for row in 0..rows {
            for column in 0..columns {
                let brick_pos = vec2(
                    offset_x + column as f32 * (BRICK_SIZE.x + GAP_BETWEEN_BRICKS),
                    offset_y + row as f32 * (BRICK_SIZE.y + GAP_BETWEEN_BRICKS),
                );

                commands.spawn((
                    SpriteBundle {
                        transform: Transform {
                            translation: brick_pos.extend(0.0),
                            ..default()
                        },
                        sprite: Sprite {
                            color: BRICK_COLOR,
                            custom_size: Some(BRICK_SIZE),
                            ..default()
                        },
                        ..default()
                    },
                    Brick,
                    Collider { size: BRICK_SIZE },
                ));
            }
        }
    }

    //Scoreboard
    commands.spawn((TextBundle::from_sections([
        TextSection::new(
            "Score: ",
            TextStyle {
                font_size: SCOREBOARD_FONT_SIZE,
                color: TEXT_COLOR,
                ..default()
            },
        ),
        TextSection::from_style(TextStyle {
            font_size: SCOREBOARD_FONT_SIZE,
            color: SCORE_COLOR,
            ..default()
        }),
    ])
    .with_style(Style {
        position_type: PositionType::Absolute,
        top: SCOREBOARD_TEXT_PADDING,
        left: SCOREBOARD_TEXT_PADDING,
        ..default()
    }),));
}

fn move_paddle(
    input: Res<Input<KeyCode>>,
    time_step: Res<FixedTime>,
    mut query: Query<&mut Transform, With<Paddle>>,
) {
    let mut paddle_transform = query.single_mut();

    let mut direction = 0.0;
    if input.pressed(KeyCode::A) {
        direction -= 1.0;
    }
    if input.pressed(KeyCode::D) {
        direction += 1.0;
    }

    let mut new_x =
        paddle_transform.translation.x + direction * PADDLE_SPEED * time_step.period.as_secs_f32();

    new_x = new_x.min(RIGHT_WALL - (WALL_THICKNESS + PADDLE_SIZE.x) * 0.5);
    new_x = new_x.max(LEFT_WALL + (WALL_THICKNESS + PADDLE_SIZE.x) * 0.5);

    paddle_transform.translation.x = new_x;
}

fn apply_velocity(mut query: Query<(&mut Transform, &Velocity)>, time_step: Res<FixedTime>) {
    let dt = time_step.period.as_secs_f32();
    for (mut transform, velocity) in &mut query {
        transform.translation.x += velocity.x * dt;
        transform.translation.y += velocity.y * dt;
    }
}

fn check_ball_collisions(
    mut commands: Commands,
    mut score: ResMut<Scoreboard>,
    collision_sound: Res<CollisionSound>,
    mut ball_query: Query<(&mut Velocity, &Transform, &Ball)>,
    mut collider_query: Query<(Entity, &Transform, &Collider, Option<&mut Brick>)>, // Note the mutability for Brick
) {
    for (mut ball_velocity, ball_transform, ball) in &mut ball_query {
        for (other_entity, transform, other, opt_brick) in &mut collider_query {
            let collision = collide(
                ball_transform.translation,
                ball.size,
                transform.translation,
                other.size,
            );

            let mut reflect_x = false;
            let mut reflect_y = false;
            if let Some(collision) = collision {
                match collision {
                    Collision::Left => reflect_x = ball_velocity.x > 0.0,
                    Collision::Right => reflect_x = ball_velocity.x < 0.0,
                    Collision::Top => reflect_y = ball_velocity.y < 0.0,
                    Collision::Bottom => reflect_y = ball_velocity.y > 0.0,
                    Collision::Inside => { /* do nothing */ }
                }

                if reflect_x {
                    ball_velocity.x *= -1.;
                }
                if reflect_y {
                    ball_velocity.y *= -1.;
                }

                if opt_brick.is_some() {
                    score.score += 1;
                    commands.entity(other_entity).despawn();
                }

                //play sound
                commands.spawn(AudioBundle {
                    source: collision_sound.clone(),
                    settings: PlaybackSettings::DESPAWN,
                });
            }
        }
    }
}

fn update_scoreboard(score: Res<Scoreboard>, mut query: Query<&mut Text>) {
    let mut text = query.single_mut();
    text.sections[1].value = score.score.to_string();
}
