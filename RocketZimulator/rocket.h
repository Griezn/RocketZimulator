#pragma once
#include <SFML/Graphics.hpp>
#include "texture_manager.h"


class rocket {
public:
    rocket();
    ~rocket();

    //public functions
    void render(sf::RenderTarget& target) const;
    void move(float y);
    void rotate(float angle);
    void set_position(float x, float y);
    void set_rotation(float x);
    bool in_bounds();

    //physics
    float calculate_x_pos(float time) const;
    float calculate_y_pos(float time) const;
    void calculate_velocity();
    float returnVelocity() const;

    

private:
    //private vars
    int rocket_width_{0};
    int rocket_height_{0};
    double rocket_angle_{0};
    double start_vel_{0};
    float rocketVelocity_ = -0.1;
    float rocketAcceleration_ = 0.0001;
   
    //private objects
    //sf::SoundBuffer buffer_;
    //sf::Sound sound_;
    sf::Sprite rocket_sprite_;
    texture_manager tx_manager_;

    //private functions
    void init_rocket();
};
