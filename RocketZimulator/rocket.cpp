#include "rocket.h"

#include <iostream>

constexpr auto pi = 3.14159265;
constexpr auto rad = pi / 180;
constexpr auto gravity = 9.81; // m/s^2
constexpr auto ground_level = 86664; //at this y-coordinate is the world ground

void rocket::init_rocket(){
    this->rocket_sprite_ = tx_manager_.create_sprite("assets/textures/rocekt.png");
    this->rocket_width_ = rocket_sprite_.getTextureRect().width;
    this->rocket_height_ = rocket_sprite_.getTextureRect().height;
    this->setOrigin(rocket_width_ / 2, rocket_height_ / 2);
    this->setPosition( 512 + 1024, 648 + (112 * 768));
    this->rocket_angle = 0;
}

void rocket::update_mass(sf::Time elapsed){
    mass_ -=  m_dot_ * elapsed.asSeconds();
}

void rocket::calculate_a() {
    acceleration_ = (thrust_ - gravity * mass_) / mass_;
}

sf::Vector2f rocket::calculate_pos(){
	float x = 0;
    float y = (acceleration_ * pow(t_plus.asSeconds(), 2))/2;

    return sf::Vector2f(x, y);
}

void rocket::update_alt(){
    altitude_ = this->getPosition().y - 86664;
}

void rocket::draw(sf::RenderTarget& target, sf::RenderStates states) const{
    states.transform *= getTransform();

    target.draw(this->rocket_sprite_, states);
}

void rocket::reset(){
    this->rocket_sprite_.setPosition(512 + 1024, 648 + (112 * 768));
    this->rocket_sprite_.setRotation(0);
    this->rocket_angle = 0;
}

void rocket::go_for_launch(sf::Time time){
    t_plus += time;

    std::cout << "Rocket go four launch: T+ " << t_plus.asSeconds() << std::endl;

    if (t_plus >= burn_time_) {
        state = rocket_state::meco;
        thrust_ = 0;
    }
    if (state == rocket_state::meco && altitude_ <= 4600) {
        state = rocket_state::landing;
    }

    switch (state) {
    case rocket_state::launch:
        update_mass(time);
        calculate_a();
        break;

    case rocket_state::meco:
        acceleration_ -= (gravity * mass_) * time.asSeconds();
        break;

    case rocket_state::landing:
        thrust_ = 2268666;
        m_dot_ = 820;

        update_mass(time);
        calculate_a();
        break;
    }
    
    this->move(calculate_pos()); // move the rocket
    update_alt();
}


rocket::rocket() {
    this->init_rocket();
}

rocket::~rocket() = default;
