#pragma once

#include "GameObject/MovableObjects/MovableObject.h"
#include "GameObject/MovableObjects/Block.h"
#include <memory>
#include "PlayerStates/PlayerState.h"


class Level;
class PlayState;
class Block;
using BlockVector = std::vector<Block>;
using CurrentState = std::unique_ptr<PlayerState>;


struct Stats {
	int m_distance;
	int m_coins;
	int m_lives;

	Stats() {
		m_distance = 0;
		m_coins = 0;
		m_lives = 3;
	}
};

class SquareBird : public MovableObject {
public:
	SquareBird(Level& level ,PlayState& play);
	void changeEffectState(std::unique_ptr<PlayerState> state);
	void handleCollisionWithBlock(Block& block);
	void handleCollisionWithMovingMonster(MovingEnemies& enemy);
	void handleCollisionWithStaticMonster(StaticEnemies& enemy);
	void setStartingPosition(sf::Vector2f firstPos);
	virtual void handleCollision(GameObject& other);
	void render(sf::RenderWindow& window);
	sf::Vector2f getStartingPos() const;
	void handleEvent(sf::Event event);
	void reduceLifeAndClearBlocks();
	void setLives(int lives);
	int getRemainingLives()const;
	void update(float dt);
	void popFirstBlock();
	Stats getStats()const;
	void addScore();
	void resetCoins();
	void addCoin();
	void jump();
	void die();

private:
	PlayState& m_playState;
	sf::Vector2f m_startingPos;
	Level& m_level;
	Stats m_stats;
	CurrentState m_currentState;
	BlockVector m_blocks;
};

