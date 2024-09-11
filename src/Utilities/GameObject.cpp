#include "Utilities/GameObject.h"
#include <iostream>
//----------------------------------------------------------------------------
GameObject::GameObject(sf::Sprite sprite) :m_sprite(sprite), m_toDelete(false)
{}
//----------------------------------------------------------------------------
void GameObject::draw(sf::RenderWindow& window) const
{
	window.draw(m_sprite);
}
//----------------------------------------------------------------------------
sf::Vector2f GameObject::getPosition() const
{
	return m_sprite.getPosition();
}
//----------------------------------------------------------------------------
void GameObject::setPosition(sf::Vector2f pos)
{
	m_sprite.setPosition(pos);
}
//----------------------------------------------------------------------------
void GameObject::setSprite(sf::Sprite sprite)
{
	m_sprite = sprite;
}
//----------------------------------------------------------------------------
void GameObject::setTexture(sf::Texture& texture)
{
	m_sprite.setTexture(texture);
}
//----------------------------------------------------------------------------
sf::Sprite GameObject::getSprite() const
{
	return m_sprite;
}
//----------------------------------------------------------------------------
bool GameObject::isColided(GameObject& other)
{
	return m_sprite.getGlobalBounds().intersects(other.getGlobalBounds());
}
//----------------------------------------------------------------------------
void GameObject::setToDelete(bool toDelete)
{
	m_toDelete = toDelete;
}
//----------------------------------------------------------------------------
bool GameObject::getToDelete() const
{
	return m_toDelete;
}
//----------------------------------------------------------------------------
sf::FloatRect GameObject::getGlobalBounds() const // bounding rectangle of the object 
{
	return m_sprite.getGlobalBounds();
}
//----------------------------------------------------------------------------