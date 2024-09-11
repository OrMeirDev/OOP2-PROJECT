#include "Utilities/Level.h"
#include <fstream>
#include <iostream>
#include "Utilities/Consts.h"
#include <filesystem>
#include "Utilities/ResourceManager.h"
#include"GameObject/MovableObjects/SquareBird.h"
#include "GameStates/PlayState.h"
#include "Utilities/StaticObjectsFactory.h"
#include "Utilities/CollisionManager.h"
#include "Utilities/MovingObjectsFactory.h"
//----------------------------------------------------------------------------
Level::Level(PlayState& playstate):m_playState(playstate),m_levelEndX(0)
{
	m_timer = sf::Time::Zero;
    m_background.setTexture(ResourceManager::instance().getTexture(PARALLAX_TEXTURE));
}
//----------------------------------------------------------------------------
void Level::loadLevel(std::string levelName)
{
    std::ifstream levelFile(levelName);
    if (!levelFile) {

        throw(std::runtime_error("Couldnt open level"));
    }
    levelFile >> m_levelEndX;
    std::string line;
    //m_levelEndX =(std::to_integer(std::getline(levelFile, line)));
    while (std::getline(levelFile, line))
    {
        std::istringstream iss(line);
        int objectNum;

        iss >> objectNum;
        makeObject(iss, objectNum);

    }
}
//----------------------------------------------------------------------------
void Level::makeObject(std::istringstream& iss, int object)
{
    sf::Vector2f location;
    float x, y;
    char type;
    iss >> x >> y >> type;
    location.x = x;
    location.y = y;

    if (object == GameObjectNumber::BIRD) {
        m_playState.setBird(createSprite(BIRD_TEXTURE, x, y, sf::Vector2f(0, 0)));
    }
    if (static_cast<GameObjectType>(type) == GameObjectType::MOVEABLE && object != GameObjectNumber::BIRD) {
        m_MovableObjects.emplace_back(std::move(MovingObjectFactory::createObject((GameObjectNumber)object, { x,y })));
    }
    else if (static_cast<GameObjectType>(type) == GameObjectType::UNMOVEABLE) {
        m_unMoveableObjects.emplace_back(std::move(StaticObjectsFactory::createObject((GameObjectNumber)object, { x,y })));
    }
}
//----------------------------------------------------------------------------
void Level::update(sf::Time dt,float backgroundX, float backgroundY,int birdX)
{
    if (birdX >= m_levelEndX)
    {
        resetAllData();
        m_playState.increaseCurrLevel();
    }

    m_background.setPosition({backgroundX,backgroundY});
    std::for_each(m_MovableObjects.begin(), m_MovableObjects.end(), [dt](std::unique_ptr<MovableObject>& moveable) { moveable->move(dt.asSeconds()); });
    std::erase_if(m_unMoveableObjects, [](std::unique_ptr<UnmovableObject>& unmoveable) { return unmoveable->getToDelete(); });
    std::erase_if(m_MovableObjects, [](std::unique_ptr<MovableObject>& moveable) { return moveable->getToDelete(); });
}
//----------------------------------------------------------------------------
void Level::draw(sf::RenderWindow& window)
{ 
    window.draw(m_background);
    std::for_each(m_unMoveableObjects.begin(), m_unMoveableObjects.end(), [&window](std::unique_ptr<UnmovableObject>& unmoveable) {unmoveable->draw(window); });
    std::for_each(m_MovableObjects.begin(), m_MovableObjects.end(), [&window](std::unique_ptr<MovableObject>& moveable) {moveable->draw(window); });
}
//----------------------------------------------------------------------------
void Level::resetAllData()
{
  m_unMoveableObjects.clear();
  m_MovableObjects.clear();
}
//----------------------------------------------------------------------------
void Level::handleCollisions(SquareBird& bird)
{
    for (auto& moveable : m_MovableObjects) {
        bird.handleCollision(*moveable);
    }
    
    for (auto& unmoveable : m_unMoveableObjects) {
        bird.handleCollision(*unmoveable);
    }
}
//----------------------------------------------------------------------------
void Level::resetPositions()
{
    for (auto& movable : m_MovableObjects)
    {
        movable->setPosition(movable->getStartingPos());
    }
}
//----------------------------------------------------------------------------
sf::Sprite Level::createSprite(const std::string texture ,const int x , const int y, sf::Vector2f origin)
{
    sf::Sprite sprite;
    sprite.setPosition(sf::Vector2f(x,y));
    sprite.setTexture(ResourceManager::instance().getTexture(texture));
    sprite.setOrigin(origin);
    return sprite;
}
//----------------------------------------------------------------------------