#include "environment.h"
#include <iostream>

environment::environment()
: screen_width_(1024),
  screen_height_(768),
  event_(),
	view_(sf::FloatRect(1024, 768 *6, 1024, 768)),
  current_gamestate_(game_state::menu){
    this->init_systems();
	this->init_menu();
	this->init_tilemap();
    this->init_rocket();
}

environment::~environment(){
	delete this->window_;
	delete this->menu_;
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

void environment::init_tilemap(){
	const int level[] =
	{
		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
		0, 0, 0,
		1, 1, 1,
		2, 2, 2
	};

	if (!tilemap_.load("assets/textures/landscape.png", sf::Vector2u(1024, 768), level, 3, 7)) {
		std::cout << "could not load tilemap!" << std::endl;
	}
}

void environment::poll_event(){
	while (this->window_->pollEvent(event_)) {
		switch (event_.type) {
		case sf::Event::Closed:
			this->current_gamestate_ = game_state::exit;
			break;
		case sf::Event::Resized:
			sf::FloatRect visibleArea(0.f, 0.f, event_.size.width, event_.size.height);
			window_->setView(sf::View(visibleArea));
			break;
		}
	}
}

// TODO: fix reset
void environment::handle_input(){
	//keyboard input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
		//this->rocket_->move();
		this->rocket_->move(0, -0.5);
		this->center_view();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		//this->rocket_->move();
		this->rocket_->move(0, 0.5);
		this->center_view();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		rocket_->move(-0.5, 0);
		this->center_view();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		rocket_->move(0.5, 0);
		this->center_view();
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
		//launch
		rocket_->move(0.5, 0.5);
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
		
		window_->setView(view_);
		window_->draw(tilemap_);
		window_->draw(*rocket_);
	}
	this->window_->display();
}

// TODO: bug rocket disappearing into a void when going down
// TODO: add a limit for the ground
void environment::center_view(){
	auto rWorldPos = this->rocket_->getPosition();
	auto screenPos = this->window_->mapCoordsToPixel(rWorldPos);
	std::cout << screenPos.x << " " << screenPos.y << '\n';

	// check the x-bounds
	if (screenPos.x <= 80) {
		auto offset = 80 - screenPos.x;
		this->view_.move(-offset, 0);
	}
	else if (screenPos.x >= 920) {
		auto offset = screenPos.x - 920;
		this->view_.move(offset, 0);
	}

	// check the y-bounds
	if (screenPos.y <= 85) {
		auto offset = 85 - screenPos.y;
		this->view_.move(0, -offset);
	}
	else if (screenPos.y >= 650) {
		auto offset = screenPos.x - 650;
		this->view_.move(0, offset);
	}
}

void environment::init_rocket() {
    this->rocket_ = new rocket();
}
