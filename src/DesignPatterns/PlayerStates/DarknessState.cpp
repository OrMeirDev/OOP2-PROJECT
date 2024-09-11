#include "PlayerStates/DarknessState.h"

#include "GameObject/MovableObjects/SquareBird.h"
#include "Utilities/Consts.h"
#include "PlayerStates/NormalPlayerState.h"
#include <iostream>
#include <cmath>
//----------------------------------------------------------------------------
DarknessState::DarknessState(SquareBird& player):m_player(player),m_effectTimer(0),m_hole(1000.f),m_currentRadius(1000.f)
{
	m_hole.setFillColor(sf::Color(255,255,255,0));
	m_renderTexture.create(WINDOW_WIDTH * 5, WINDOW_HEIGHT);
	m_hole.setOrigin(m_hole.getRadius(), m_hole.getRadius());
	m_animationTimer = sf::seconds(2);
	m_endEffectAnimationTimer = sf::Time::Zero;
}
//----------------------------------------------------------------------------
void DarknessState::handleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up) {
		m_player.jump();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down) {
		m_player.popFirstBlock();
	}
}
//----------------------------------------------------------------------------
void DarknessState::draw(sf::RenderWindow& window)
{
	m_player.draw(window);
	window.draw(m_hole);
	m_renderTexture.clear();
	m_renderTexture.draw(m_hole, sf::BlendNone);
	m_renderTexture.display();

	sf::Sprite overlaySprite(m_renderTexture.getTexture());
	overlaySprite.setColor(sf::Color(255, 255, 255, 255));
	window.draw(overlaySprite, sf::BlendMultiply);
}
//----------------------------------------------------------------------------
void DarknessState::update(float dt)
{
	if (m_effectTimer < sf::seconds(EFFECT_TIME).asSeconds()) {
		m_effectTimer += dt;
	}
	else {
		if (m_endEffectAnimationTimer < sf::seconds(2)) {
			m_currentRadius = std::lerp(270.f, 1200.f, m_endEffectAnimationTimer / sf::seconds(2));
			m_endEffectAnimationTimer += sf::seconds(0.015);
		}
		else {
			m_player.changeEffectState(std::make_unique<NormalPlayerState>(m_player));
			return;
		}
	}
	animateRadius(dt);
	
}
//----------------------------------------------------------------------------
void DarknessState::handleCollisionWithBlock(Block& block)
{
	// Get the top boundary position of object2
	auto object2Bounds = block.getGlobalBounds();
	auto newYPos = object2Bounds.top - 63;

	// Get the current x position of object1
	auto currentXPos = m_player.getPosition().x;

	sf::Vector2f position(currentXPos, newYPos);
	// Set the position of object1 to align its top with object2's top
	m_player.setPosition(position);
}
//----------------------------------------------------------------------------
void DarknessState::handleCollisionWithMovingMonster(MovingEnemies&)
{
	m_player.die();
}
//----------------------------------------------------------------------------
void DarknessState::handleCollisionWithStaticMonster(StaticEnemies&)
{
	m_player.die();
}
//----------------------------------------------------------------------------
void DarknessState::animateRadius(float dt)
{
	if (m_animationTimer > sf::Time::Zero) {
		m_currentRadius = DARKNESS_ANIMATION_END_VAL + DARKNESS_ANIMATION_START_VAL * m_animationTimer / sf::seconds(2);
		m_animationTimer -= sf::seconds(0.015);
	}
	m_player.move(dt);
	sf::Vector2f playerPos = m_player.getPosition();
	int width = m_player.getGlobalBounds().width / 2;
	int height = m_player.getGlobalBounds().height / 2;
	sf::Vector2f playerCenter(playerPos.x + width, playerPos.y + height);
	m_hole.setRadius(m_currentRadius);
	m_hole.setOrigin(m_hole.getRadius(), m_hole.getRadius());
	m_hole.setPosition(playerCenter);
}
//----------------------------------------------------------------------------