#include "GameObject/Traps/FloorSpikes.h"
#include "Utilities/StaticObjectsFactory.h"

//----------------------------------------------------------------------------
bool FloorSpikes::m_registerIt = StaticObjectsFactory::registerObject(GameObjectNumber::FLOORSPIKES, [](sf::Vector2f pos) -> std::unique_ptr<UnmovableObject> {
	sf::Sprite sprite;
	sprite.setPosition(pos);
	sprite.setTexture(ResourceManager::instance().getTexture(FLOORSPIKES_TEXTURE));
	return std::make_unique<FloorSpikes>(sprite);
	});
//----------------------------------------------------------------------------
