#include "GameObject/MovableObjects/SquareBird.h"
#include "GameObject/UnmovableObjects/Floor.h"
#include "GameObject/UnmovableObjects/Coin.h"
#include "GameObject/UnmovableObjects/Wall.h"
#include "GameObject/UnmovableObjects/Ceiling.h"
#include "GameObject/UnmovableObjects/House.h"
#include "GameObject/MovableObjects/Block.h"
#include "GameObject/StaticEnemies/Snake.h"
#include "GameObject/Traps/DarknessTrap.h"
#include "GameObject/Traps/MagnifierTrap.h"
#include "Utilities/CollisonHandlers.h"
#include "Utilities/CollisionManager.h"
#include <iostream>
#include "Utilities/Consts.h"
#include <cmath>
#include <memory>
#include "PlayerStates/EnlargeState.h"
#include "PlayerStates/GhostState.h"
#include "PlayerStates/DarknessState.h"
#include <PlayerStates/NormalPlayerState.h>
#include "GameObject/MovingEnemies/SquareBatMan.h"
#include "GameObject/MovingEnemies/SquareEagle.h"
#include "GameObject/Traps/CeilingSpikes.h"
#include "GameObject/Traps/FloorSpikes.h"
#include "GameObject/PowerUp/Ghost.h"


//----------------------------------------------------------------------------
void addAllCollisions()
{
	CollisonManager::instance().addCollision(typeid(SquareBird), typeid(Floor), &handleCollisionBirdToFloor);
	CollisonManager::instance().addCollision(typeid(SquareBird), typeid(Ghost), &handleCollisionBirdToGhost);
	CollisonManager::instance().addCollision(typeid(SquareBird), typeid(SquareEagle), &handleCollisionBirdToSquareEagle);
	CollisonManager::instance().addCollision(typeid(SquareBird), typeid(CeilingSpikes), &handleCollisionBirdToCeilingSpikes);
	CollisonManager::instance().addCollision(typeid(SquareBird), typeid(FloorSpikes), &handleCollisionBirdToFloorSpikes);
	CollisonManager::instance().addCollision(typeid(Block), typeid(FloorSpikes), &handleCollisionBlockToFloorSpikes);
	CollisonManager::instance().addCollision(typeid(Block), typeid(SquareEagle), &handleCollisionBlockToSquareEagle);
	CollisonManager::instance().addCollision(typeid(SquareBird), typeid(SquareBatMan), &handleCollisionBirdToBatMan);
	CollisonManager::instance().addCollision(typeid(Block), typeid(SquareBatMan), &handleCollisionBlockToBatMan);
	CollisonManager::instance().addCollision(typeid(Block), typeid(Floor), &handleCollisionBlockToFloor);
	CollisonManager::instance().addCollision(typeid(SquareBird), typeid(Coin), &handleCollisionBirdToCoin);
	CollisonManager::instance().addCollision(typeid(SquareBird), typeid(Wall), &handleCollisionBirdToWall);
	CollisonManager::instance().addCollision(typeid(SquareBird), typeid(Snake), &handleCollisionBirdToSnake);
	CollisonManager::instance().addCollision(typeid(SquareBird), typeid(Block), &handleCollisionBirdToBlock);
	CollisonManager::instance().addCollision(typeid(Block), typeid(Block), &handleCollisionBlockToBlock);
	CollisonManager::instance().addCollision(typeid(Block), typeid(Wall), &handleCollisionBlockToWall);
	CollisonManager::instance().addCollision(typeid(Block), typeid(Snake), &handleCollisionBlockToSnake);
	CollisonManager::instance().addCollision(typeid(SquareBird), typeid(Ceiling), &handleCollisionBirdToCeiling);
	CollisonManager::instance().addCollision(typeid(SquareBird), typeid(DarknessTrap), &handleCollisionBirdToDarknessTrap);
	CollisonManager::instance().addCollision(typeid(SquareBird), typeid(MagnifierTrap), &handleCollisionBirdToMagnifierTrap);
}
//----------------------------------------------------------------------------
void handleCollisionBirdToFloor(GameObject& object1, GameObject& object2)
{
	SquareBird& bird = static_cast<SquareBird&>(object1);

	if (bird.getPosition().y + BIRD_OFFSET > object2.getPosition().y){
		bird.die();
	}
	else{
		auto object2Bounds = object2.getGlobalBounds();
		auto newYPos = object2Bounds.top - object1.getGlobalBounds().height;
		auto currentXPos = object1.getPosition().x;
		sf::Vector2f position(currentXPos, newYPos);
		object1.setPosition(position);
	}
}
//----------------------------------------------------------------------------
void handleCollisionBlockToFloor(GameObject& object1, GameObject& object2)
{
	Block& block = static_cast<Block&>(object1);

	if (block.getPosition().y + BLOCK_OFFSET > object2.getPosition().y){
		block.setToDelete(true);
	}
	else{
		auto object2Bounds = object2.getGlobalBounds();
		auto newYPos = object2Bounds.top - object1.getGlobalBounds().height + 3; // +3 to make the block closer to the floor
		auto currentXPos = object1.getPosition().x;
		sf::Vector2f position(currentXPos, newYPos);
		object1.setPosition(position);
	}
}
//----------------------------------------------------------------------------
void handleCollisionBirdToCoin(GameObject& object1, GameObject& object2) {

	SquareBird& bird = static_cast<SquareBird&>(object1);
	bird.addCoin();
	object2.setToDelete(true);
	ResourceManager::instance().playSound(COIN_SOUND);
}
//----------------------------------------------------------------------------
void handleCollisionBirdToWall(GameObject& object1, GameObject& object2) {

	SquareBird& bird = static_cast<SquareBird&>(object1);
	Wall& wall = static_cast<Wall&>(object2);

	const auto wallBounds = wall.getGlobalBounds();
	const auto birdBounds = bird.getGlobalBounds();
	sf::FloatRect intersectionRect;
	birdBounds.intersects(wall.getGlobalBounds(), intersectionRect);

	if (intersectionRect.top == birdBounds.top)
	{
		handleCollisionBirdToCeiling(object1, object2);
	}
	else if (intersectionRect.top + intersectionRect.height == birdBounds.top + birdBounds.height)
	{
		auto object2Bounds = object2.getGlobalBounds();
		auto newYPos = object2Bounds.top - object1.getGlobalBounds().height;
		auto currentXPos = object1.getPosition().x;
		sf::Vector2f position(currentXPos, newYPos);
		object1.setPosition(position);
	}
	else
	{
		bird.die();
	}

}
//----------------------------------------------------------------------------
void handleCollisionBirdToSnake(GameObject& object1, GameObject& object2) {

	SquareBird& bird = static_cast<SquareBird&>(object1);
	Snake& snake = static_cast<Snake&>(object2);
	bird.handleCollisionWithStaticMonster(snake);
}
//----------------------------------------------------------------------------
void handleCollisionBirdToBlock(GameObject& object1, GameObject& object2)
{
	SquareBird& bird = static_cast<SquareBird&>(object1);
	Block& block = static_cast<Block&>(object2);
	bird.handleCollisionWithBlock(block);
}
//----------------------------------------------------------------------------
void handleCollisionBlockToBlock(GameObject& object1, GameObject& object2)
{
	auto object2Bounds = object2.getGlobalBounds();
	auto newYPos = object2Bounds.top - BLOCK_OFFSET;
	auto currentXPos = object1.getPosition().x;
	sf::Vector2f position(currentXPos, newYPos);
	object1.setPosition(position);
}
//----------------------------------------------------------------------------
void handleCollisionBlockToWall(GameObject& object1, GameObject& object2)
{
	Block& block = static_cast<Block&>(object1);
	Wall& wall = static_cast<Wall&>(object2);

	if (block.getPosition().y + BLOCK_OFFSET >= wall.getPosition().y){
		block.setToDelete(true);
	}
	else if (block.getPosition().y < wall.getPosition().y){
		handleCollisionBlockToFloor(object1, object2);
	}
}
//----------------------------------------------------------------------------
void handleCollisionBlockToSnake(GameObject& object1, GameObject& object2)
{
	Block& block = static_cast<Block&>(object1);
	block.setToDelete(true);
}
//----------------------------------------------------------------------------
void handleCollisionBirdToCeiling(GameObject& object1, GameObject& object2)
{
	SquareBird& bird = static_cast<SquareBird&>(object1);
	float offSet = object2.getGlobalBounds().height;
	float newYPos = bird.getPosition().y + offSet;
	bird.setPosition({ bird.getPosition().x, newYPos });
	bird.popFirstBlock();
}
//----------------------------------------------------------------------------
void handleCollisionBirdToDarknessTrap(GameObject& object1, GameObject& object2)
{
	object2.setToDelete(true);
	SquareBird& bird = static_cast<SquareBird&>(object1);
	ResourceManager::instance().playSound(DARKNESS_SOUND);
	bird.changeEffectState(std::make_unique<DarknessState>(bird));
}
//----------------------------------------------------------------------------
void handleCollisionBirdToMagnifierTrap(GameObject& object1, GameObject& object2)
  {
	object2.setToDelete(true);
	SquareBird& bird = static_cast<SquareBird&>(object1);
	ResourceManager::instance().playSound(ENLARGE_SOUND);
	bird.changeEffectState(std::make_unique<EnlargeState>(bird));
}
//----------------------------------------------------------------------------
void handleCollisionBirdToBatMan(GameObject& object1, GameObject& object2)
{
	SquareBird& bird = static_cast<SquareBird&>(object1);
	SquareBatMan& batman = static_cast<SquareBatMan&>(object2);
	bird.handleCollisionWithMovingMonster(batman);
}
//----------------------------------------------------------------------------
void handleCollisionBlockToBatMan(GameObject& object1, GameObject& object2)
{
	Block& block = static_cast<Block&>(object1);
	block.setToDelete(true);
}
//----------------------------------------------------------------------------
void handleCollisionBirdToSquareEagle(GameObject& object1, GameObject& object2)
{
	SquareBird& bird = static_cast<SquareBird&>(object1);
	SquareEagle& eagle = static_cast<SquareEagle&>(object2);
	bird.handleCollisionWithMovingMonster(eagle);
}
//----------------------------------------------------------------------------
void handleCollisionBirdToCeilingSpikes(GameObject& object1, GameObject& object2)
{
	SquareBird& bird = static_cast<SquareBird&>(object1);
	bird.die();
}
//----------------------------------------------------------------------------
void handleCollisionBirdToFloorSpikes(GameObject& object1, GameObject& object2)
{
	SquareBird& bird = static_cast<SquareBird&>(object1);
	bird.die();
}
//----------------------------------------------------------------------------
void handleCollisionBlockToFloorSpikes(GameObject& object1, GameObject& object2)
{
	Block& block = static_cast<Block&>(object1);
	block.setToDelete(true);
}
//----------------------------------------------------------------------------
void handleCollisionBlockToSquareEagle(GameObject& object1, GameObject& object2)
{
	Block& block = static_cast<Block&>(object1);
	block.setToDelete(true);
}
//----------------------------------------------------------------------------
void handleCollisionBirdToGhost(GameObject& object1, GameObject& object2)
{
	object2.setToDelete(true);
	SquareBird& bird = static_cast<SquareBird&>(object1);
	ResourceManager::instance().playSound(GHOST_SOUND);
	bird.changeEffectState(std::make_unique<GhostState>(bird));
}
//----------------------------------------------------------------------------
