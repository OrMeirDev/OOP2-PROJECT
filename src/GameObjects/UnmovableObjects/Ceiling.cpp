#include "GameObject/UnmovableObjects/Ceiling.h"
#include "Utilities/StaticObjectsFactory.h"
#include <memory>
#include "Utilities/ResourceManager.h"
#include "Utilities/Consts.h"


bool Ceiling::m_registerIt = StaticObjectsFactory::registerObject(GameObjectNumber::CEILING, [](sf::Vector2f pos) -> std::unique_ptr<UnmovableObject> {
	sf::Sprite sprite;
	sprite.setPosition(pos);
	sprite.setTexture(ResourceManager::instance().getTexture(CEILING_TEXTURE));
	return std::make_unique<Ceiling>(sprite);
	});
