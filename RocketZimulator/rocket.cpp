#include "rocket.h"

constexpr auto pi = 3.14159265;
constexpr auto rad = pi / 180;
constexpr auto gravity = 9.81;

void rocket::init_rocket(){
    this->rocket_sprite_ = tx_manager_.create_sprite("C:/Users/seppe/source/repos/RocketZimulator/RocketZimulator/rocekt.png");
    this->rocket_width_ = rocket_sprite_.getTextureRect().width;
    this->rocket_height_ = rocket_sprite_.getTextureRect().height;
    this->rocket_sprite_.setOrigin(rocket_width_ / 2, rocket_height_ / 2);
    this->rocket_sprite_.setPosition( 512, 648);
    this->rocket_angle_ = 0;
}
void rocket::move(const float y){
    float x_ = sin(rocket_angle_ * rad) * y;
    float y_ = cos(rocket_angle_ * rad) * y;
    this->rocket_sprite_.move(-x_, y_);
    //printf("The posotion of the rocket is: %f %f\n", rocket_sprite_.getPosition().x, rocket_sprite_.getPosition().y);
}
void rocket::rotate(const float angle){
    this->rocket_sprite_.rotate(angle);
    this->rocket_angle_ = rocket_sprite_.getRotation();
    //printf("The angle of the rocket is %f\n ", rocket_angle_);
}

void rocket::set_position(const float x, const float y){
    this->rocket_sprite_.setPosition(x, y);
}

void rocket::set_rotation(float x){
    this->rocket_sprite_.setRotation(x);
    rocket_angle_ = rocket_sprite_.getRotation();
}

bool rocket::in_bounds(){
    return true;
}

float rocket::calculate_x_pos(const float time) const{
    const float vx_0 = start_vel_ * cos(rocket_angle_ * rad);
    const float x = vx_0 * time;
    return x;
}

float rocket::calculate_y_pos(const float time) const{
    const float vy_0 = start_vel_ * cos(rocket_angle_ * rad);
    constexpr  float a = -0.5 * gravity;
    const float b = vy_0;
    constexpr  float c = 0;
    const float y = (a * pow(time, 2)) + (b * time) + c;
    return y;
}

void rocket::calculate_velocity() {
    this->rocketVelocity_ = rocketVelocity_ - rocketAcceleration_;
}

float rocket::returnVelocity() const{
    return this->rocketVelocity_;
}

void rocket::render(sf::RenderTarget &target) const{
    target.draw(this->rocket_sprite_);
}

rocket::rocket() {
    this->init_rocket();
}

rocket::~rocket() = default;
