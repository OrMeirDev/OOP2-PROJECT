#include "GameObject/StaticEnemies/Snake.h"
#include "Utilities/StaticObjectsFactory.h"
#include <memory>
#include "Utilities/ResourceManager.h"
#include "Utilities/Consts.h"


bool Snake::m_registerIt = StaticObjectsFactory::registerObject(GameObjectNumber::SNAKE, [](sf::Vector2f pos) -> std::unique_ptr<UnmovableObject> {
	sf::Sprite sprite;
	sprite.setPosition(pos);
	sprite.setTexture(ResourceManager::instance().getTexture(SNAKE_TEXTURE));
	return std::make_unique<Snake>(sprite);
	});
