#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "rocket.h"
#include "background.h"
#include "menu.h"

enum class game_state {
    menu,
    settings,
	play,
	exit,
};

class environment {
public:
	environment();
	~environment();

    void run();

private:
    //private vars
    unsigned int screen_width_;
    unsigned int screen_height_;

    //objects
    sf::Event event_;
    sf::RenderWindow* window_;

    //private functions
    void menu_loop();
    void loop();
    void poll_event();
    void handle_input();
    void render() const;

	void init_systems();
    void init_menu();
    void init_rocket();
    void init_background();

    //classes
    game_state current_gamestate_;
    menu* menu_;
    rocket* rocket_;
    background* background_;
};