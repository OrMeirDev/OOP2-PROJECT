#include "GameObject/MovingEnemies/SquareBatMan.h"
#include "Utilities/MovingObjectsFactory.h"

//-----------------------------------------------------------------------------------------------------------
bool SquareBatMan::m_registerIt =  MovingObjectFactory::registerObject(GameObjectNumber::SQUAREBATMAN, [](sf::Vector2f pos) -> std::unique_ptr<MovableObject> {
	sf::Sprite sprite;
	sprite.setPosition(pos);
	sprite.setTexture(ResourceManager::instance().getTexture(SQUAREBATMAN_TEXTURE));
	return std::make_unique<SquareBatMan>(sprite,FLYING_OBJECT_GRAVITY, SQUARE_BATMAN_SPEED);
	});
//----------------------------------------------------------------------------
void SquareBatMan::move(float dt) {
    // Linear movement
    sf::Vector2f pos = getPosition();
    pos.x -= getMovementSpeed() * dt;

    // Sine wave movement
    static sf::Clock clock; // Use a static clock to track elapsed time across calls
    float elapsedTime = clock.getElapsedTime().asSeconds();
    float amplitude = 100.f; // Example amplitude
    float frequency = 3.f; // Example frequency (1 cycle per second)

    float offset = std::sin(elapsedTime * frequency) * amplitude;
    pos.y = getStartingPos().y + offset; // Adjust based on initial position or another reference point

    setPosition(pos);
}
//----------------------------------------------------------------------------