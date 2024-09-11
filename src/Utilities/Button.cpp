#include "Utilities/Button.h"

Button::Button(std::unique_ptr<Command> command, sf::Texture& texture, sf::Vector2f pos)
{
	m_sprite.setTexture(texture);
	m_sprite.setPosition(pos);
	m_command = std::move(command);
}

void Button::handleClick(sf::Vector2f pos)
{
	if (m_sprite.getGlobalBounds().contains(pos)) {
		m_command->execute();
	}
}

void Button::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}

void Button::handleHover(sf::Vector2f pos)
{
	if (m_sprite.getGlobalBounds().contains(pos))
	{
		m_sprite.setScale(1.05f, 1.05f);
	}
	else
	{
		m_sprite.setScale(1.0f, 1.0f);
	}
}

