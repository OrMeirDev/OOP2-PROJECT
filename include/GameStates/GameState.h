#pragma once

#include <SFML/Graphics.hpp>

class GameState {
public:
	virtual void handleEvents(sf::Event event,sf::RenderWindow& window) = 0;
	virtual void update(sf::Time dt) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
private:

};