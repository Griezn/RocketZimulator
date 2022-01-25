#include "environment.h"
#include <iostream>

environment::environment()
: screen_width_(1024),
  screen_height_(768),
  event_(),
  current_gamestate_(game_state::PLAY){
    this->init_systems();
	this->init_background();
    this->init_rocket();
}

environment::~environment(){
	delete this->window;
	delete this->background_;
    delete this->rocket_;
}

void environment::run(){
	while (current_gamestate_ != game_state::EXIT) {
		this->poll_event();
		this->handle_input();
		this->render();
	}
}

void environment::init_systems(){
	this->window = new sf::RenderWindow(sf::VideoMode(screen_width_, screen_height_), "Rocket Zimulator");
	this->window->setFramerateLimit(60);
	this->window->setFramerateLimit(false);

	//background_sprite_.setPosition(0, screen_height_);
}

void environment::poll_event(){
	while (this->window->pollEvent(event_)) {
		switch (event_.type) {
		case sf::Event::Closed:
			this->current_gamestate_ = game_state::EXIT;
			break;
		case sf::Event::Resized:
			this->screen_width_ = event_.size.width;
			this->screen_height_ = event_.size.height;
			break;
		}
	}
}
/*
	TODO:
		- Bad implementation of acceleration of our rocket, will make it better soon ;-)
		- Reset velocity when rocket stops moving (release Z)
		- Move bg wen rocket is to close to border
*/

void environment::handle_input() const{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		this->rocket_->move();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		this->rocket_->move();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		this->background_->move("left");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->background_->move("right");
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Delete)) {
		this->rocket_->reset();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) {
		this->rocket_->rotate(-0.3);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)) {
		this->rocket_->rotate(0.3);
	}
}

void environment::render() const{
	this->window->clear();

	this->background_->render(*window);
	this->rocket_->render(*this->window);

	this->window->display();
}

void environment::init_rocket() {
    this->rocket_ = new rocket();
}

void environment::init_background(){
	this->background_ = new background();
}
