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
    this->rocket_angle = 0;
}
void rocket::move(){
    float x_ = sin(rocket_angle * rad) * rocketVelocity_;
    float y_ = cos(rocket_angle * rad) * rocketVelocity_;
    this->rocket_sprite_.move(-x_, y_);
	this->calculate_velocity();
    //printf("The posotion of the rocket is: %f %f\n", rocket_sprite_.getPosition().x, rocket_sprite_.getPosition().y);
    printf("Velocity of the rocket now is %f\n", rocketVelocity_);

}

void rocket::rotate(const float angle){
    this->rocket_sprite_.rotate(angle);
    this->rocket_angle = rocket_sprite_.getRotation();
    //printf("The angle of the rocket is %f\n ", rocket_angle_);
}

void rocket::reset(){
    this->rocket_sprite_.setPosition(512, 648);
    this->rocket_sprite_.setRotation(0);
    this->rocketVelocity_ = start_vel_;
}

bool rocket::in_bounds(){
    return true;
}

float rocket::calculate_x_pos(const float time) const{
    const float vx_0 = start_vel_ * cos(rocket_angle * rad);
    const float x = vx_0 * time;
    return x;
}

float rocket::calculate_y_pos(const float time) const{
    const float vy_0 = start_vel_ * cos(rocket_angle * rad);
    constexpr  float a = -0.5 * gravity;
    const float b = vy_0;
    constexpr  float c = 0;
    const float y = (a * pow(time, 2)) + (b * time) + c;
    return y;
}

void rocket::calculate_velocity() {
    this->rocketVelocity_ = rocketVelocity_ - rocketAcceleration_;
}

void rocket::render(sf::RenderTarget &target) const{
    target.draw(this->rocket_sprite_);
}

rocket::rocket() {
    this->init_rocket();
}

rocket::~rocket() = default;
