#include "texture_manager.h"

sf::RectangleShape texture_manager::create_rect(const float x_size, const float y_size, const sf::Color color){
	rectangle_.setSize(sf::Vector2f(x_size, y_size));
	rectangle_.setFillColor(color);

	return rectangle_;
}

sf::Sprite texture_manager::create_sprite(const std::string& path){
	if (!texture_.loadFromFile(path)) {
		printf("Failed to load texture from: %s\n", path.c_str());
	}

	sprite_.setTexture(texture_);

	return sprite_;
}