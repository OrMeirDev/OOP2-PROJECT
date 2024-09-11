#pragma once 
#include "GameObject/UnmovableObjects/UnmovableObject.h" 

class House : public UnmovableObject {
public:
	using UnmovableObject::UnmovableObject;
private:
	static bool m_registerIt;

};