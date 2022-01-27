#include "environment.h"
#include <iostream>

environment::environment()
: screen_width_(1024),
  screen_height_(768),
  event_(),
  current_gamestate_(game_state::menu){
    this->init_systems();
	this->init_menu();
	this->init_background();
    this->init_rocket();
}

environment::~environment(){
	delete this->window_;
	delete this->menu_;
	delete this->background_;
    delete this->rocket_;
}

void environment::run(){
	if (current_gamestate_ == game_state::menu) {
		this->menu_loop();
	}
	else if (current_gamestate_ == game_state::play) {
		this->loop();
	}
}

void environment::menu_loop(){
	while (current_gamestate_ != game_state::exit) {
		this->poll_event();
		this->handle_input();
		this->render();
	}
}

void environment::loop(){
	while (current_gamestate_ != game_state::exit) {
		this->poll_event();
		this->handle_input();
		this->render();
	}
}

void environment::init_systems(){
	this->window_ = new sf::RenderWindow(sf::VideoMode(screen_width_, screen_height_), "Rocket Zimulator");
	this->window_->setFramerateLimit(60);
	this->window_->setFramerateLimit(false);

	//background_sprite_.setPosition(0, screen_height_);
}

void environment::init_menu(){
	this->menu_ = new menu();
}

void environment::poll_event(){
	while (this->window_->pollEvent(event_)) {
		switch (event_.type) {
		case sf::Event::Closed:
			this->current_gamestate_ = game_state::exit;
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
		- Move background when rocket is to close to border
*/

void environment::handle_input(){
	//keyboard input
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		this->current_gamestate_ = game_state::menu;
	}

	//mouse input
	const sf::Vector2i local_position = sf::Mouse::getPosition(*window_);
	if (this->menu_->on_play_button(local_position) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		this->current_gamestate_ = game_state::play;
	}
	if (this->menu_->on_settings_button(local_position) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		this->current_gamestate_ = game_state::settings;
	}
}

void environment::render() const{
	this->window_->clear();
	if (current_gamestate_ == game_state::menu) {
		this->menu_->render(*window_);
	}
	else if (current_gamestate_ == game_state::play) {
		this->background_->render(*window_);
		this->rocket_->render(*window_);
	}
	this->window_->display();
}

void environment::init_rocket() {
    this->rocket_ = new rocket();
}

void environment::init_background(){
	this->background_ = new background();
}
