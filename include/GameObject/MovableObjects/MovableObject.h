#pragma once
#include "Utilities/GameObject.h"
#include "Utilities/Consts.h"

class MovableObject : public GameObject{
public:
	MovableObject(sf::Sprite sprite,float gravity,int movespeed):GameObject(sprite),m_movementSpeed(movespeed),m_gravity(gravity),m_startingPos(sprite.getPosition()) {}
	virtual ~MovableObject() = default;
	virtual void move(float deltaTime);
	int getMovementSpeed() const;
	sf::Vector2f getStartingPos()const;
private:
	sf::Vector2f m_startingPos;
	float m_gravity;
	int m_movementSpeed;
};