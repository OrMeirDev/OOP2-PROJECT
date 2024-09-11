#include "GameObject/PowerUp/Ghost.h"
#include "Utilities/StaticObjectsFactory.h"

//----------------------------------------------------------------------------
bool Ghost::m_registerIt = StaticObjectsFactory::registerObject(GameObjectNumber::GHOSTPOWERUP, [](sf::Vector2f pos) -> std::unique_ptr<UnmovableObject> {
	sf::Sprite sprite;
	sprite.setPosition(pos);
	sprite.setTexture(ResourceManager::instance().getTexture(GHOST_POWERUP_TEXTURE));
	return std::make_unique<Ghost>(sprite);
	});
//----------------------------------------------------------------------------
