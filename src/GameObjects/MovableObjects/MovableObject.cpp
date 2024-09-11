#include "GameObject/MovableObjects/MovableObject.h"


//-----------------------------------------------------------------------------------------------------------
void MovableObject::move(float deltaTime)
{
	sf::Vector2f pos = getPosition();
	pos.x += getMovementSpeed() * deltaTime;
	pos.y += m_gravity;
	setPosition(pos);
}
//-----------------------------------------------------------------------------------------------------------
int MovableObject::getMovementSpeed() const
{
	return m_movementSpeed;
}
//-----------------------------------------------------------------------------------------------------------
sf::Vector2f MovableObject::getStartingPos()const
{
	return m_startingPos;
}
//-----------------------------------------------------------------------------------------------------------