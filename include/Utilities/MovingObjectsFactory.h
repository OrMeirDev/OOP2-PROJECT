#pragma once

#include <unordered_map>
#include <string>
#include "GameObject/MovableObjects/MovableObject.h"
#include <memory>
#include <SFML/Graphics.hpp>

using mymovingmap = std::unordered_map<GameObjectNumber, std::unique_ptr<MovableObject>(*)(sf::Vector2f)>;

class MovingObjectFactory {
public:
	static bool registerObject(GameObjectNumber type, std::unique_ptr<MovableObject>(*f)(sf::Vector2f pos));
	static std::unique_ptr<MovableObject> createObject(GameObjectNumber type, sf::Vector2f pos);
private:
	static mymovingmap& getMap();
};

