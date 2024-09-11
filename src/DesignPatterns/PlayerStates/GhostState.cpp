#include "PlayerStates/GhostState.h"
#include "GameObject/MovableObjects/SquareBird.h"
#include "PlayerStates/NormalPlayerState.h"
#include "GameObject/UnmovableObjects/Coin.h"
#include "Utilities/ResourceManager.h"
#include "Utilities/Consts.h"


GhostState::GhostState(SquareBird& player) :m_player(player),m_effectTimer(0)
{
	sf::Vector2f pos = m_player.getPosition();
	sf::Sprite newSprite;
	newSprite.setPosition(pos);
	newSprite.setTexture(ResourceManager::instance().getTexture(GHOST_SQUAREBIRD_TEXTURE));
	m_player.setSprite(newSprite);
}
//----------------------------------------------------------------------------
void GhostState::handleEvent(sf::Event event)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up) {
		m_player.jump();
	}
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down) {
		m_player.popFirstBlock();
	}
}
//----------------------------------------------------------------------------
void GhostState::draw(sf::RenderWindow& window)
{
	m_player.draw(window);
}
//----------------------------------------------------------------------------
void GhostState::update(float dt)
{
	if (m_effectTimer < sf::seconds(EFFECT_TIME).asSeconds()) {
		m_effectTimer += dt;
	}
	else {
		m_player.changeEffectState(std::make_unique<NormalPlayerState>(m_player));
		return;
	}
	m_player.move(dt);
}
//----------------------------------------------------------------------------
void GhostState::handleCollisionWithBlock(Block& block)
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

//-----------------------------------------------------------------------------------------------------------------------------------------------------