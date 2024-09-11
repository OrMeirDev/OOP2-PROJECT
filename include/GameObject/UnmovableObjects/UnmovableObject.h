#pragma once

#include "Utilities/GameObject.h"

class UnmovableObject : public GameObject {
public:
	virtual ~UnmovableObject() = default;
	using GameObject::GameObject;
private:

};