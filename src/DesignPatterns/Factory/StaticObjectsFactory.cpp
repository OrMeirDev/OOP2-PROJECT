#include "Utilities/StaticObjectsFactory.h"


bool StaticObjectsFactory::registerObject(GameObjectNumber type, std::unique_ptr<UnmovableObject>(*f)(sf::Vector2f pos))
{
	getMap().emplace(type, f);
	return true;
}

std::unique_ptr<UnmovableObject> StaticObjectsFactory::createObject(GameObjectNumber type, sf::Vector2f pos)
{
	auto it = getMap().find(type);
	if (it == getMap().end()) {
		return nullptr;
	}
	return it->second(pos);
}

mymap& StaticObjectsFactory::getMap()
{
	static mymap m_map;
	return m_map;
}
