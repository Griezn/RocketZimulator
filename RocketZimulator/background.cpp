#include "background.h"

background::background(){
	this->init_background();
}

background::~background() = default;

void background::render(sf::RenderTarget &target) const{
	target.draw(this->background_sprite_);
	target.draw(this->background_sprite_left_);
	target.draw(this->background_sprite_right_);
}

void background::move(std::string direction){
	if (direction == "left") {
		if (background_sprite_.getPosition().x < background_width_) {
			//attached to center
			background_sprite_.move(2.f, 0.f);
			background_sprite_left_.setPosition(background_sprite_.getPosition().x - background_width_, 0);
			background_sprite_right_.setPosition(background_sprite_.getPosition().x + background_width_, 0);
		}
		else {
			background_sprite_.setPosition(0, 0);
			background_sprite_left_.setPosition(background_sprite_.getPosition().x - background_width_, 0);
			background_sprite_right_.setPosition(background_sprite_.getPosition().x + background_width_, 0);
		}
	}
	if (direction == "right") {
		if (background_sprite_.getPosition().x > -background_width_) {
			background_sprite_.move(-2.f, 0.f);
			background_sprite_left_.setPosition(background_sprite_.getPosition().x - background_width_, 0);
			background_sprite_right_.setPosition(background_sprite_.getPosition().x + background_width_, 0);
		}
		else {
			background_sprite_.setPosition(0, 0);
			background_sprite_left_.setPosition(background_sprite_.getPosition().x - background_width_, 0);
			background_sprite_right_.setPosition(background_sprite_.getPosition().x + background_width_, 0);
		}
	}
}

void background::init_background(){
	this->background_sprite_ = tx_manager_.create_sprite("C:/Users/evari/Desktop/RocketZimulator/RocketZimulator/bg.png");
	this->background_sprite_left_ = tx_manager_.create_sprite("C:/Users/evari/Desktop/RocketZimulator/RocketZimulator/bg.png");
	this->background_sprite_right_ = tx_manager_.create_sprite("C:/Users/evari/Desktop/RocketZimulator/RocketZimulator/bg.png");
	this->background_width_ = background_sprite_.getTextureRect().width;
	this->background_height_ = background_sprite_.getTextureRect().height;
	//background_sprite_.setOrigin(0, background_height_);

	this->background_sprite_left_.setPosition(-background_width_, 0);
	this->background_sprite_right_.setPosition(background_width_, 0);
}
