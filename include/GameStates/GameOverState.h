#pragma once
#include "GameStates/GameState.h"
#include "Utilities/ResourceManager.h"
#include "Utilities/Consts.h"
#include "GameStates/MenuState.h"

class GameController;

class GameOverState : public GameState
{
public:
	GameOverState(MenuState& menuState,GameController& controller) ;
	virtual void handleEvents(sf::Event event, sf::RenderWindow& window);
	virtual void update(sf::Time dt);
	virtual void draw(sf::RenderWindow& window);
private:
	Button m_backToMenuButton;
	MenuState& m_menuState;
};