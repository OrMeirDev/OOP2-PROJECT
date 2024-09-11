#include "Utilities/CollisionManager.h"

CollisonManager& CollisonManager::instance()
{
	static CollisonManager m_instance = CollisonManager();
	return m_instance;
}

void CollisonManager::addCollision(const std::type_index& class1, const std::type_index& class2, CollisionFunction func)
{
	m_collisionMap[std::make_pair(class1,class2)] = func;
}

CollisionFunction CollisonManager::getFunc(const std::type_index& class1, const std::type_index& class2)
{
	auto it = m_collisionMap.find(std::make_pair(class1, class2));
	if (it == m_collisionMap.end()) {
		return nullptr;
	}
	return it->second;
}
