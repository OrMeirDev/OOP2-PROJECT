#include "Utilities/MovingObjectsFactory.h"

bool MovingObjectFactory::registerObject(GameObjectNumber type, std::unique_ptr<MovableObject>(*f)(sf::Vector2f pos))
{
	getMap().emplace(type, f);
	return true;
}

std::unique_ptr<MovableObject> MovingObjectFactory::createObject(GameObjectNumber type, sf::Vector2f pos)
{
	auto it = getMap().find(type);
	if (it == getMap().end()) {
		return nullptr;
	}
	return it->second(pos);
}

mymovingmap& MovingObjectFactory::getMap()
{
	static mymovingmap m_map;
	return m_map;
}

