#pragma once

#include <unordered_map>
#include <string>
#include "GameObject/UnmovableObjects/UnmovableObject.h" 
#include <memory>
#include <SFML/Graphics.hpp>
#include "Consts.h"

using mymap = std::unordered_map<GameObjectNumber, std::unique_ptr<UnmovableObject>(*)(sf::Vector2f)>;

class StaticObjectsFactory {
public:
	static bool registerObject(GameObjectNumber type, std::unique_ptr<UnmovableObject>(*f)(sf::Vector2f pos));
	static std::unique_ptr<UnmovableObject> createObject(GameObjectNumber type, sf::Vector2f pos);
private:
	static mymap& getMap();
};