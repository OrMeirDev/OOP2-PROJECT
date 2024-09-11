#pragma once 
#include "GameObject/UnmovableObjects/UnmovableObject.h" 

class Floor : public UnmovableObject {
public:
	using UnmovableObject::UnmovableObject;
private:
	static bool m_registerIt;

};