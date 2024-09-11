#pragma once

#include <SFML/Graphics.hpp>
#include "PlayerStates/PlayerState.h"

class SquareBird;
class GameObject;

class DarknessState : public PlayerState {
public:
	DarknessState(SquareBird& player);
	virtual void handleEvent(sf::Event event);
	virtual void draw(sf::RenderWindow& window);
	virtual void update(float dt);
	virtual void handleCollisionWithBlock(Block& block);
	virtual void handleCollisionWithMovingMonster(MovingEnemies&);
	virtual void handleCollisionWithStaticMonster(StaticEnemies&);
	void animateRadius(float dt);
private:
	SquareBird& m_player;
	sf::RenderTexture m_renderTexture;
	sf::CircleShape m_hole;
	sf::Time m_animationTimer;
	sf::Time m_endEffectAnimationTimer;
	float m_effectTimer;
	float m_currentRadius;
};