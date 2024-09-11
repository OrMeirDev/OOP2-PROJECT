#pragma once

#include <SFML/Graphics.hpp>
#include "ResourceManager.h"

enum class GameObjectType {
	UNMOVEABLE = 's',
	MOVEABLE = 'm'
};

class GameObject {
public:
	GameObject():m_toDelete(false){};
	GameObject(sf::Sprite);
	virtual ~GameObject() = default;
	void draw(sf::RenderWindow& window) const;

	sf::Vector2f getPosition() const;
	void setPosition(sf::Vector2f pos);
	void setSprite(sf::Sprite sprite);
	void setTexture(sf::Texture& texture);
	sf::Sprite getSprite()const;
	virtual bool isColided(GameObject& other);
	void setToDelete(bool toDelete);
	bool getToDelete() const;
	sf::FloatRect getGlobalBounds() const;
	

private:
	sf::Sprite m_sprite;
	bool m_toDelete;

};

