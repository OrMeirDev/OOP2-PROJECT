#include "GameObject/UnmovableObjects/House.h"
#include "Utilities/StaticObjectsFactory.h"
#include <memory>
#include "Utilities/ResourceManager.h"
#include "Utilities/Consts.h"


bool House::m_registerIt = StaticObjectsFactory::registerObject(GameObjectNumber::HOUSE, [](sf::Vector2f pos) -> std::unique_ptr<UnmovableObject> {
	sf::Sprite sprite;
	sprite.setPosition(pos);
	sprite.setTexture(ResourceManager::instance().getTexture(HOUSE_TEXTURE));
	return std::make_unique<House>(sprite);
	});