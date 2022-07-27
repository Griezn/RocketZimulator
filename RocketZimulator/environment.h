#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "rocket.h"
#include "tilemap.h"
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
    // private vars
    unsigned int screen_width_;
    unsigned int screen_height_;

    // objects
    sf::View view_;
    sf::Event event_;
    sf::RenderWindow* window_;

    // private functions
    void menu_loop();
    void loop();
    void poll_event();
    void handle_input();
    void render() const;
    void center_view();
    void rocket_handler(sf::Clock &clock);

    // initialization
	void init_systems();
    void init_menu();
    void init_tilemap();
    void init_rocket();

    // classes
    game_state current_gamestate_;
    menu* menu_;
    rocket* rocket_;
    TileMap tilemap_;


};

// Starting view
// (1024, 86016)
//////////////////////////////////////////////
//                                          //
//                                          //
//                                          //
//                                          //
//                 1536                     //
//                                          //
//                                          //
//                                          //
//                                          //
////////////////////////////////////////////// -> 86784
