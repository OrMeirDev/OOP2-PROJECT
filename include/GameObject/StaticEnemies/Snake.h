#pragma once 
#include "GameObject/StaticEnemies/StaticEnemies.h" 

class Snake : public StaticEnemies {
public:
	using StaticEnemies::StaticEnemies;
private:
	static bool m_registerIt;

};