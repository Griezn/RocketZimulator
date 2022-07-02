#include "rocket.h"

constexpr auto pi = 3.14159265;
constexpr auto rad = pi / 180;
constexpr auto gravity = 9.81;

void rocket::init_rocket(){
    this->rocket_sprite_ = tx_manager_.create_sprite("assets/textures/rocekt.png");
    this->rocket_width_ = rocket_sprite_.getTextureRect().width;
    this->rocket_height_ = rocket_sprite_.getTextureRect().height;
    this->setOrigin(rocket_width_ / 2, rocket_height_ / 2);
    this->setPosition( 512 + 1024, 648 + (6 * 768));
    this->rocket_angle = 0;
}

void rocket::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();

    target.draw(this->rocket_sprite_, states);
}

/*
void rocket::move(){
    float x_ = sin(rocket_angle * rad) * -0.5;
    float y_ = cos(rocket_angle * rad) * -0.5;
    this->rocket_sprite_.move(-x_, y_);
	this->calculate_velocity();
    //printf("The posotion of the rocket is: %f %f\n", rocket_sprite_.getPosition().x, rocket_sprite_.getPosition().y);
    //printf("Velocity of the rocket now is %f\n", rocketVelocity_);

}

void rocket::rotate(const float angle){
    this->rocket_sprite_.rotate(angle);
    this->rocket_angle = rocket_sprite_.getRotation();
    //printf("The angle of the rocket is %f\n ", rocket_angle_);
}
*/

void rocket::reset(){
    this->rocket_sprite_.setPosition(512, 648);
    this->rocket_sprite_.setRotation(0);
    this->rocket_angle = 0;
    this->rocketVelocity_ = start_vel_;
}

rocket::rocket() {
    this->init_rocket();
}

rocket::~rocket() = default;
