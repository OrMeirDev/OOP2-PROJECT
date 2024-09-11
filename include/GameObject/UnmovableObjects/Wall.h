#pragma once 
#include "GameObject/UnmovableObjects/UnmovableObject.h" 

class Wall : public UnmovableObject {
public:
	using UnmovableObject::UnmovableObject;
private:
	static bool m_registerIt;

};