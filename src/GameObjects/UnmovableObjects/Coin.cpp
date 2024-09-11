#include "GameObject/UnmovableObjects/Coin.h"
#include "Utilities/StaticObjectsFactory.h"
#include <memory>
#include "Utilities/ResourceManager.h"
#include "Utilities/Consts.h"

//----------------------------------------------------------------------------
bool Coin::m_registerIt = StaticObjectsFactory::registerObject(GameObjectNumber::COIN, [](sf::Vector2f pos) -> std::unique_ptr<UnmovableObject> {
	sf::Sprite sprite;
	sprite.setPosition(pos);
	sprite.setTexture(ResourceManager::instance().getTexture(COIN_TEXTURE));
	return std::make_unique<Coin>(sprite);
	});
//----------------------------------------------------------------------------
