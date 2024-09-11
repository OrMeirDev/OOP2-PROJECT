#include "GameObject/UnmovableObjects/Floor.h"
#include "Utilities/StaticObjectsFactory.h"
#include <memory>
#include "Utilities/ResourceManager.h"
#include "Utilities/Consts.h"

//----------------------------------------------------------------------------
bool Floor::m_registerIt = StaticObjectsFactory::registerObject(GameObjectNumber::FLOOR, [](sf::Vector2f pos) -> std::unique_ptr<UnmovableObject> {
	sf::Sprite sprite;
	sprite.setPosition(pos);
	sprite.setTexture(ResourceManager::instance().getTexture(FLOOR_TEXTURE));
	return std::make_unique<Floor>(sprite);
	});
//----------------------------------------------------------------------------