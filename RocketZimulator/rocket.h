#pragma once
#include <SFML/Graphics.hpp>
#include "texture_manager.h"

enum class rocket_state {
	ready,
    launch,
    meco, // main engine cutoff
    landing
};


// Missing params:
// Thrust
// Drag
// Weight


class rocket : public sf::Drawable, public sf::Transformable{
public:
    rocket();
    ~rocket();

    void reset();

    // TODO: create the launch function
    void go_for_launch(sf::Time time);

    //public vars
    double rocket_angle{ 0 };
    float velocity{ 0 };

    rocket_state state{ rocket_state::ready };

private:
    //private vars
    int rocket_width_{0};
    int rocket_height_{0};
    int altitude_{ 0 };

    // physics vars
    int original_mass_{ 541300 };
    int mass_{ original_mass_ }; // kg
    int thrust_{ 6806000 }; // N
    int m_dot_{ 2462 }; // kg/s
    float acceleration_{ 0 }; // m/s
    sf::Time t_plus{ sf::seconds(0) }; // s
    sf::Time burn_time_{ sf::seconds(100) }; // s

    void update_mass(sf::Time elapsed);
    void calculate_a();
    sf::Vector2f calculate_pos();
    void update_alt();

    sf::Sprite rocket_sprite_;
    //sf::FloatRect rect_;
    texture_manager tx_manager_;

    void init_rocket();

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
