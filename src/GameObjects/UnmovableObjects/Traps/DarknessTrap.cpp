#include "GameObject/Traps/DarknessTrap.h"
#include "Utilities/StaticObjectsFactory.h"
#include <memory>
#include "Utilities/ResourceManager.h"
#include "Utilities/Consts.h"

//----------------------------------------------------------------------------
bool DarknessTrap::m_registerIt = StaticObjectsFactory::registerObject(GameObjectNumber::DARKNESSTRAP, [](sf::Vector2f pos) -> std::unique_ptr<UnmovableObject> {
	sf::Sprite sprite;
	sprite.setPosition(pos);
	sprite.setTexture(ResourceManager::instance().getTexture(DARKNESS_TEXTURE));
	return std::make_unique<DarknessTrap>(sprite);
	});
//----------------------------------------------------------------------------
