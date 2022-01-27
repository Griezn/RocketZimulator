#pragma once
#include <SFML/Graphics.hpp>
#include "texture_manager.h"

class menu
{
public:
	menu();
	~menu();

	void render(sf::RenderTarget& target) const;
	bool on_play_button(sf::Vector2i pos);
	bool on_settings_button(sf::Vector2i pos);

private:
	sf::Font font;
	sf::Text play_text_;
	sf::Text settings_text_;
	sf::Sprite logo_;

	void init_menu();
	void init_font();

	texture_manager texture_manager_;

};

