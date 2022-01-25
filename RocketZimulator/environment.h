#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "rocket.h"
#include "background.h"

enum class game_state {
	PLAY,
	EXIT,
};

class environment {
public:
	environment();
	~environment();

    void run(); 
    void poll_event();
    void handle_input() const;
    void render() const;

	sf::RenderWindow* window;

private:
    //private vars
    unsigned int screen_width_;
    unsigned int screen_height_;

    //objects
    sf::Event event_;
	game_state current_gamestate_;

    //private functions
    void init_systems();
    void init_rocket();
    void init_background();

    //rocket
    rocket* rocket_;
    background* background_;
};