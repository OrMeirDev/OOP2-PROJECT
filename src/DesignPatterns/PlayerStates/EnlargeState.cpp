#include "PlayerStates/EnlargeState.h"
#include "GameObject/MovableObjects/SquareBird.h"
#include "PlayerStates/NormalPlayerState.h"
#include "Utilities/ResourceManager.h"
#include "Utilities/Consts.h"

//----------------------------------------------------------------------------
EnlargeState::EnlargeState(SquareBird& player):m_player(player),m_effectTimer(0)
{
	sf::Vector2f pos = m_player.getPosition();
	sf::Sprite newSprite;
	newSprite.setPosition(pos);
	newSprite.setTexture(ResourceManager::instance().getTexture(ENLARGED_BIRD_TEXTURE));
	m_player.setSprite(newSprite);
}
//----------------------------------------------------------------------------
void EnlargeState::handleEvent(sf::Event event)
{
}
//----------------------------------------------------------------------------
void EnlargeState::draw(sf::RenderWindow& window)
{
	m_player.draw(window);
}
//----------------------------------------------------------------------------
void EnlargeState::update(float dt)
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
void EnlargeState::handleCollisionWithBlock(Block& block)
{
	block.setToDelete(true);
}
//----------------------------------------------------------------------------
void EnlargeState::handleCollisionWithMovingMonster(MovingEnemies&)
{
	m_player.die();
}
//----------------------------------------------------------------------------
void EnlargeState::handleCollisionWithStaticMonster(StaticEnemies&)
{
	m_player.die();
}
//----------------------------------------------------------------------------