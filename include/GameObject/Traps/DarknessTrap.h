#pragma once 
#include "GameObject/Traps/Trap.h" 
 

class DarknessTrap : public Trap {
public:
	using Trap::Trap;
private:
	static bool m_registerIt;

};