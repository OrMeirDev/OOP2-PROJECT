#pragma once

#include <SFML/Graphics.hpp>

class Block;
class GameObject;
class MovingEnemies;
class StaticEnemies;

class PlayerState {
public:
	virtual ~PlayerState() = default;
	virtual void handleEvent(sf::Event event) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update(float dt) = 0;
	virtual void handleCollisionWithBlock(Block& block) = 0;
	virtual void handleCollisionWithMovingMonster(MovingEnemies&) = 0;
	virtual void handleCollisionWithStaticMonster(StaticEnemies&) = 0;
private:

};