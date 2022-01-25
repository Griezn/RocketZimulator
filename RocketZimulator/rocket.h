#pragma once
#include <SFML/Graphics.hpp>
#include "texture_manager.h"


class rocket {
public:
    rocket();
    ~rocket();

    //public functions
    void render(sf::RenderTarget& target) const;
    void move();
    void rotate(float angle);
    void reset();
    bool in_bounds();

    //physics
    float calculate_x_pos(float time) const;
    float calculate_y_pos(float time) const;
    void calculate_velocity();

    //public vars
    double rocket_angle{ 0 };

private:
    //private vars
    int rocket_width_{0};
    int rocket_height_{0};
    double start_vel_{-0.1};
    double rocketVelocity_{start_vel_};
    double rocketAcceleration_{ 0.0001 };
   
    //private objects
    //sf::SoundBuffer buffer_;
    //sf::Sound sound_;
    sf::Sprite rocket_sprite_;
    texture_manager tx_manager_;
    //private functions
    void init_rocket();
};
