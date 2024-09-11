#pragma once

#include <SFML/Graphics.hpp>
#include "PlayerStates/PlayerState.h"

class SquareBird;
class GameObject;

class EnlargeState : public PlayerState {
public:
	EnlargeState(SquareBird& player);
	virtual void handleEvent(sf::Event event);
	virtual void draw(sf::RenderWindow& window);
	virtual void update(float dt);
	virtual void handleCollisionWithBlock(Block& block);
	virtual void handleCollisionWithMovingMonster(MovingEnemies&);
	virtual void handleCollisionWithStaticMonster(StaticEnemies&);
private:
	SquareBird& m_player;
	float m_effectTimer;
};