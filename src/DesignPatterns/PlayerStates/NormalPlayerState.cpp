#include "PlayerStates/NormalPlayerState.h"
#include "GameObject/MovableObjects/SquareBird.h"
#include "Utilities/ResourceManager.h"
#include "Utilities/Consts.h"
#include "GameObject/MovingEnemies/MovingEnemies.h"
#include "GameObject/StaticEnemies/StaticEnemies.h"
#include <memory>

NormalPlayerState::NormalPlayerState(SquareBird& player):m_player(player)
{
	sf::Vector2f pos = m_player.getPosition();
	sf::Sprite newSprite;
	newSprite.setPosition(pos);
	newSprite.setTexture(ResourceManager::instance().getTexture(BIRD_TEXTURE));
	m_player.setSprite(newSprite);
}
//----------------------------------------------------------------------------
void NormalPlayerState::handleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up) {
		m_player.jump();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down) {
		m_player.popFirstBlock();
	}
}
//----------------------------------------------------------------------------
void NormalPlayerState::draw(sf::RenderWindow& window)
{
	m_player.draw(window);
}
//----------------------------------------------------------------------------
void NormalPlayerState::update(float dt)
{	
	m_player.move(dt);
}
//----------------------------------------------------------------------------
void NormalPlayerState::handleCollisionWithBlock(Block& block)
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
void NormalPlayerState::handleCollisionWithMovingMonster(MovingEnemies& enemy)
{
	m_player.die();
}
//----------------------------------------------------------------------------
void NormalPlayerState::handleCollisionWithStaticMonster(StaticEnemies& enemy)
{
	m_player.die();
}
//----------------------------------------------------------------------------