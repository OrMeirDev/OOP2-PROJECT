#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include "Commands/Command.h"

class Button {
public:
	Button(std::unique_ptr<Command> command, sf::Texture& texture, sf::Vector2f pos);
	void handleClick(sf::Vector2f pos);
	void draw(sf::RenderWindow& window)const;
	void handleHover(sf::Vector2f);
private:
	sf::Sprite m_sprite;
	std::unique_ptr<Command> m_command;
};