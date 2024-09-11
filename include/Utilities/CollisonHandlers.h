#pragma once

#include "GameObject.h"

void addAllCollisions();

void handleCollisionBirdToFloor(GameObject& object1, GameObject& object2);
void handleCollisionBlockToFloor(GameObject& object1, GameObject& object2);
void handleCollisionBirdToCoin(GameObject& object1, GameObject& object2);
void handleCollisionBirdToWall(GameObject& object1, GameObject& object2);
void handleCollisionBirdToSnake(GameObject& object1, GameObject& object2);
void handleCollisionBirdToBlock(GameObject& object1, GameObject& object2);
void handleCollisionBlockToBlock(GameObject& object1, GameObject& object2);
void handleCollisionBlockToWall(GameObject& object1, GameObject& object2);
void handleCollisionBlockToSnake(GameObject& object1, GameObject& object2);
void handleCollisionBirdToCeiling(GameObject& object1, GameObject& object2);
void handleCollisionBirdToDarknessTrap(GameObject& object1, GameObject& object2);
void handleCollisionBirdToMagnifierTrap(GameObject& object1, GameObject& object2);
void handleCollisionBirdToBatMan(GameObject& object1, GameObject& object2);
void handleCollisionBlockToBatMan(GameObject& object1, GameObject& object2);
void handleCollisionBirdToSquareEagle(GameObject& object1, GameObject& object2);
void handleCollisionBirdToCeilingSpikes(GameObject& object1, GameObject& object2);
void handleCollisionBirdToFloorSpikes(GameObject& object1, GameObject& object2);
void handleCollisionBlockToFloorSpikes(GameObject& object1, GameObject& object2);
void handleCollisionBlockToSquareEagle(GameObject& object1, GameObject& object2);
void handleCollisionBirdToGhost(GameObject& object1, GameObject& object2);