#include "menu.h"
menu::menu(){
	this->init_font();
	this->init_menu();
}

menu::~menu() = default;

void menu::init_menu(){
	this->play_text_.setFont(font);
	this->play_text_.setString("Play");
	this->play_text_.setCharacterSize(36);
	this->play_text_.setOrigin(play_text_.getLocalBounds().width / 2, play_text_.getLocalBounds().height / 2);
	this->play_text_.setPosition(512, 384);

	this->settings_text_.setFont(font);
	this->settings_text_.setString("Settings");
	this->settings_text_.setCharacterSize(36);
	this->settings_text_.setOrigin(settings_text_.getLocalBounds().width / 2, settings_text_.getLocalBounds().height / 2);
	this->settings_text_.setPosition(512, 430);

	this->logo_ = texture_manager_.create_sprite("assets/textures/logo.png");
	this->logo_.setScale(sf::Vector2f(0.75, 0.75));
	this->logo_.setOrigin(logo_.getLocalBounds().width / 2, logo_.getLocalBounds().height / 2);
	this->logo_.setPosition(512, 150);
}

void menu::init_font(){
	if (!font.loadFromFile("assets/fonts/VCR_OSD_MONO_1.001.ttf")) {
		printf("Font could not be loaded!");
	}
}

bool menu::on_play_button(sf::Vector2i pos){
	if (play_text_.getGlobalBounds().contains(sf::Vector2f(pos))) {
		this->play_text_.setStyle(sf::Text::Bold);
		return true;
	}
	this->play_text_.setStyle(sf::Text::Regular);
	return false;
}

bool menu::on_settings_button(sf::Vector2i pos){
	if (settings_text_.getGlobalBounds().contains(sf::Vector2f(pos))) {
		this->settings_text_.setStyle(sf::Text::Bold);
		return true;
	}
	this->settings_text_.setStyle(sf::Text::Regular);
	return false;
}


void menu::render(sf::RenderTarget& target) const{
	target.draw(play_text_);
	target.draw(settings_text_);
	target.draw(logo_);
}
