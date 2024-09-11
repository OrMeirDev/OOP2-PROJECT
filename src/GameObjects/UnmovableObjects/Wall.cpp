#include "GameObject/UnmovableObjects/Wall.h"
#include "Utilities/StaticObjectsFactory.h"
#include <memory>
#include "Utilities/ResourceManager.h"
#include "Utilities/Consts.h"


bool Wall::m_registerIt = StaticObjectsFactory::registerObject(GameObjectNumber::WALL, [](sf::Vector2f pos) -> std::unique_ptr<UnmovableObject> {
	sf::Sprite sprite;
	sprite.setPosition(pos);
	sprite.setTexture(ResourceManager::instance().getTexture(WALL_TEXTURE));
	return std::make_unique<Wall>(sprite);
	});
