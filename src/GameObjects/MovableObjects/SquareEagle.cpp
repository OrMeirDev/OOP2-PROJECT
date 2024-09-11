#include "GameObject/MovingEnemies/SquareEagle.h"
#include "Utilities/MovingObjectsFactory.h"



//-----------------------------------------------------------------------------------------------------------
bool SquareEagle::m_registerIt = MovingObjectFactory::registerObject(GameObjectNumber::SQUAREEAGLE, [](sf::Vector2f pos) -> std::unique_ptr<MovableObject> {
	sf::Sprite sprite;
	sprite.setPosition(pos);
	sprite.setTexture(ResourceManager::instance().getTexture(SQUAREEAGLE_TEXTURE));
	return std::make_unique<SquareEagle>(sprite,FLYING_OBJECT_GRAVITY,SQUARE_EAGLE_SPEED);
	});
//-----------------------------------------------------------------------------------------------------------
void SquareEagle::move(float dt)
{
	sf::Vector2f pos = getPosition();
	pos.x -= getMovementSpeed() * dt;
	pos.y = getPosition().y;
	setPosition(pos);
}
//-----------------------------------------------------------------------------------------------------------
