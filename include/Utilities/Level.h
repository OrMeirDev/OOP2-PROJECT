#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
#include "GameObject/MovableObjects/SquareBird.h"
#include "GameObject/UnmovableObjects/UnmovableObject.h"

#include <typeindex>
#include <typeinfo>

class PlayState;

using UnmovableVector = std::vector<std::unique_ptr<UnmovableObject>>;
using MovableVector = std::vector<std::unique_ptr<MovableObject>>;

class Level {
public:
	Level(PlayState& playstate);
	void loadLevel(std::string);
	void makeObject(std::istringstream& iss, int object);
	void update(sf::Time dt, float backgroundX, float backgroundY,int birdX);
	void draw(sf::RenderWindow& window);
	void resetAllData();
	void handleCollisions(SquareBird&);
	void resetPositions();
	sf::Sprite createSprite(const std::string texture,const int,const int, sf::Vector2f origin);

private:
	PlayState& m_playState;
	UnmovableVector m_unMoveableObjects;
	MovableVector m_MovableObjects;
	sf::Time m_timer;
	sf::Sprite m_background;
	int m_levelEndX;
};