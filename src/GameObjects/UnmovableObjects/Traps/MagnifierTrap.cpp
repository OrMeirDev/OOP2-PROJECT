#include "GameObject/Traps/MagnifierTrap.h"
#include "Utilities/StaticObjectsFactory.h"
#include <memory>
#include "Utilities/ResourceManager.h"
#include "Utilities/Consts.h"

//----------------------------------------------------------------------------
bool MagnifierTrap::m_registerIt = StaticObjectsFactory::registerObject(GameObjectNumber::MAGNIFIERTRAP, [](sf::Vector2f pos) -> std::unique_ptr<UnmovableObject> {
	sf::Sprite sprite;
	sprite.setPosition(pos);
	sprite.setTexture(ResourceManager::instance().getTexture(MAGNIFIER_TEXTURE));
	return std::make_unique<MagnifierTrap>(sprite);
	});
//----------------------------------------------------------------------------
