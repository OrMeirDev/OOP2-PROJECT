#pragma once 
#include "GameObject/PowerUp/PowerUp.h" 


class Ghost : public PowerUp {
public:
	using PowerUp::PowerUp;
private:
	static bool m_registerIt;

};