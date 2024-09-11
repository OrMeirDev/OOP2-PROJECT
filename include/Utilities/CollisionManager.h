#pragma once

#include <map>
#include <typeindex>
#include <typeinfo>
#include "GameObject.h"

using CollisionFunction = void (*)(GameObject&, GameObject&);
using CollisionKey = std::pair<std::type_index, std::type_index>;
using CollisionMap = std::map<CollisionKey, CollisionFunction>;

class CollisonManager {
public:
	static CollisonManager& instance();
	void addCollision(const std::type_index& class1, const std::type_index& class2,CollisionFunction);
	CollisionFunction getFunc(const std::type_index& class1, const std::type_index& class2);
private:
	CollisonManager() = default;
	CollisonManager(const CollisonManager& other) = delete;

	CollisionMap m_collisionMap;
};