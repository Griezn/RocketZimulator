#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "texture_manager.h"

class background {
public:
	background();
	~background();

	void render(sf::RenderTarget& target) const;
	void move(std::string direction);
private:
	//private vars
	int background_width_{0};
	int background_height_{0};

	//objects
	texture_manager tx_manager_;
	sf::Sprite background_sprite_;
	sf::Sprite background_sprite_left_;
	sf::Sprite background_sprite_right_;

	//private functions
	void init_background();
};
