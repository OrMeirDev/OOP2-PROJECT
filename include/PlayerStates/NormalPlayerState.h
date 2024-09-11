#pragma once

#include "PlayerState.h"

class SquareBird;
class GameObject;

class NormalPlayerState : public PlayerState {
public:
	NormalPlayerState(SquareBird& player);
	virtual void handleEvent(sf::Event event);
	virtual void draw(sf::RenderWindow& window);
	virtual void update(float dt);
	virtual void handleCollisionWithBlock(Block& block);
	virtual void handleCollisionWithMovingMonster(MovingEnemies&);
	virtual void handleCollisionWithStaticMonster(StaticEnemies&);
private:
	SquareBird& m_player;
};