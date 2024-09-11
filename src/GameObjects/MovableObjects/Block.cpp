#include "GameObject/MovableObjects/Block.h"
#include "Utilities/MovingObjectsFactory.h"
#include "Utilities/Consts.h"
#include <iostream>

//-----------------------------------------------------------------------------------------------------------
Block::Block(sf::Sprite sprite):MovableObject(sprite,GRAVITY,BIRD_OBJECT_SPEED) {}
//-----------------------------------------------------------------------------------------------------------
