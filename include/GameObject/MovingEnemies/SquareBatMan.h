#pragma once

#include "GameObject/MovingEnemies/MovingEnemies.h"

class SquareBatMan : public MovingEnemies {
public:
	using MovingEnemies::MovingEnemies;
	virtual void move(float dt);
private:

	static bool m_registerIt;
};