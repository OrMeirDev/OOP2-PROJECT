#include "GameObject/MovableObjects/SquareBird.h"
#include "GameStates/PlayState.h"
#include "Utilities/Consts.h"
#include "Utilities/Level.h"
#include "Utilities/MovingObjectsFactory.h"
#include <iostream>
#include <memory>
#include "PlayerStates/NormalPlayerState.h"
#include "PlayerStates/EnlargeState.h"
#include "GameObject/MovableObjects/Block.h"
#include "Utilities/CollisonHandlers.h"
#include "Utilities/CollisionManager.h"

//-----------------------------------------------------------------------------------------------------------
SquareBird::SquareBird(Level& level, PlayState& play) :m_level(level), m_playState(play), MovableObject(getSprite(), GRAVITY, BIRD_OBJECT_SPEED) {}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::setStartingPosition(sf::Vector2f firstPos)
{
	m_startingPos = firstPos;
	m_currentState = std::make_unique<NormalPlayerState>(*this);
}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::reduceLifeAndClearBlocks()
{
	if (m_stats.m_lives > 0)
	{
		m_stats.m_lives = m_stats.m_lives - 1;
		m_level.resetPositions();
		m_blocks.clear();
		ResourceManager::instance().playSound(FAIL_SOUND);
	}
}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::setLives(int lives)
{
	m_stats.m_lives = lives;
}
//-----------------------------------------------------------------------------------------------------------
int SquareBird::getRemainingLives() const
{
	return m_stats.m_lives;
}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::addScore()
{
	m_stats.m_distance = getPosition().x;
}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::resetCoins()
{
	m_stats.m_coins = INITIAL_COINS_NUMBER;
}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::addCoin()
{
	m_stats.m_coins = m_stats.m_coins + 1;
}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::jump()
{
	sf::Vector2f pos = getPosition();
	pos.x = getPosition().x;
	pos.y = getPosition().y - JUMPHEIGHT;
	setPosition(pos);

	sf::Vector2f blockOffset(0,65);
	sf::Sprite block(ResourceManager::instance().getTexture(BLOCK_TEXTURE));
	block.setPosition(pos + blockOffset);
	m_blocks.emplace_back(block);
	ResourceManager::instance().playSound(BLOCK_SOUND);
}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::die()
{
	reduceLifeAndClearBlocks();
	setPosition(getStartingPos());
	changeEffectState(std::make_unique<NormalPlayerState>(*this));
}
//-----------------------------------------------------------------------------------------------------------
sf::Vector2f SquareBird::getStartingPos() const
{
	return m_startingPos;
}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::update(float dt) {

	std::for_each(m_blocks.begin(), m_blocks.end(), [dt](Block& block) { block.move(dt); });
	addScore();
	m_currentState->update(dt);

	for (int i = 0; i < m_blocks.size(); i++)
	{
		for (int j = i+1; j < m_blocks.size(); j++) // i+1 to not work with a block and itslef
		{
			if (m_blocks[i].isColided(m_blocks[j])) {

				auto func = CollisonManager::instance().getFunc(typeid(m_blocks[i]), typeid(m_blocks[j]));
				if (func) {
					func(m_blocks[j], m_blocks[i]);
				}

			}
		}
	}
	if (!m_blocks.empty()) {
		const int endOfBlocks = m_blocks.size() - 1;
		if (this->isColided(m_blocks[endOfBlocks])) {
			handleCollisionBirdToBlock(*this, m_blocks[endOfBlocks]);
		}
	}

	std::erase_if(m_blocks, [](Block& block) { return block.getToDelete(); });
}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::handleCollisionWithBlock(Block& block)
{
	m_currentState->handleCollisionWithBlock(block);
}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::handleCollisionWithMovingMonster(MovingEnemies& enemy)
{
	m_currentState->handleCollisionWithMovingMonster(enemy);
}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::handleCollisionWithStaticMonster(StaticEnemies& enemy)
{
	m_currentState->handleCollisionWithStaticMonster(enemy);
}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::render(sf::RenderWindow& window){
	std::for_each(m_blocks.begin(), m_blocks.end(), [&window](Block& block) {block.draw(window); });
	m_currentState->draw(window);
	
}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::handleEvent(sf::Event event) {
	m_currentState->handleEvent(event);
}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::changeEffectState(std::unique_ptr<PlayerState> state) {
	m_currentState = std::move(state);
}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::handleCollision(GameObject& object) {
	
	for (auto& block : m_blocks)
	{
		if (block.getGlobalBounds().intersects(object.getGlobalBounds())) {
			auto func = CollisonManager::instance().getFunc(typeid(block), typeid(object));
			if (func) {
				func(block, object);
			}
		}
	}
	if (getGlobalBounds().intersects(object.getGlobalBounds())) {
		auto func = CollisonManager::instance().getFunc(typeid(*this), typeid(object));
		if (func) {
			func(*this, object);
		}
	}
}
//-----------------------------------------------------------------------------------------------------------
void SquareBird::popFirstBlock()
{
	if (!m_blocks.empty())
	{
		ResourceManager::instance().playSound(POPBLOCK_SOUND);
		m_blocks.pop_back();
	}
}
//-----------------------------------------------------------------------------------------------------------
Stats SquareBird::getStats() const
{
	return m_stats;
}
//-----------------------------------------------------------------------------------------------------------