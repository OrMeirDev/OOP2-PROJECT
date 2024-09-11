#include "GameObject/Traps/CeilingSpikes.h"
#include "Utilities/StaticObjectsFactory.h"

//----------------------------------------------------------------------------
bool CeilingSpikes::m_registerIt = StaticObjectsFactory::registerObject(GameObjectNumber::CEILINGSPIKES, [](sf::Vector2f pos) -> std::unique_ptr<UnmovableObject> {
	sf::Sprite sprite;
	sprite.setPosition(pos);
	sprite.setTexture(ResourceManager::instance().getTexture(CEILINGSPIKES_TEXTURE));
	return std::make_unique<CeilingSpikes>(sprite);
	});
//----------------------------------------------------------------------------
