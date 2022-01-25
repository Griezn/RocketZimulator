#pragma once
#include <SFML/Graphics.hpp>

class texture_manager {
public:
	/**
	 * \brief Creates a rectangle.
	 * \param x_size The width of the rectangle
	 * \param y_size The height of the rectangle
	 * \param color The color of the rectangle, must be an Sf::Color
	 * \return A sf::Rectangleshape
	 */
	sf::RectangleShape create_rect(float x_size, float y_size, sf::Color color);

	/**
	 * \brief Creates a sprite.
	 * \param path The path to the file.
	 * \return A sf::Sprite
	 */
	sf::Sprite create_sprite(const std::string& path);

private:
	sf::RectangleShape rectangle_;
	sf::Sprite sprite_;
	sf::Texture texture_;
};
