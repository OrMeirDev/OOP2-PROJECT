#pragma once

#include "GameObject/MovableObjects/SquareBird.h"


class StatusBar {
public:
	StatusBar(SquareBird& bird);

	void draw(sf::RenderWindow& window);

	void makeText(sf::Text& text, int row, int col, int num);

private:
	SquareBird& m_bird;
	sf::Sprite m_coin;
	sf::Sprite m_distance;
	sf::Sprite m_lives;
};