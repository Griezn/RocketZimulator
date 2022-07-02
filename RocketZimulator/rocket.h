#pragma once
#include <SFML/Graphics.hpp>
#include "texture_manager.h"

class rocket : public sf::Drawable, public sf::Transformable{
public:
    rocket();
    ~rocket();

    void reset();

    // TODO: create the launch function
    void launch();

    //public vars
    double rocket_angle{ 0 };

private:
    //private vars
    int rocket_width_{0};
    int rocket_height_{0};
    double start_vel_{-0.1};
    double rocketVelocity_{start_vel_};
    double rocketAcceleration_{ 0.0001 };

    sf::Sprite rocket_sprite_;
    //sf::FloatRect rect_;
    texture_manager tx_manager_;

    void init_rocket();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
