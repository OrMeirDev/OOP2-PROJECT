#pragma once

#include "GameObject/MovableObjects/MovableObject.h"
#include "Utilities/Consts.h"



class Block : public MovableObject {
public:
	Block(sf::Sprite);
private:
	static bool m_registerIt;

};