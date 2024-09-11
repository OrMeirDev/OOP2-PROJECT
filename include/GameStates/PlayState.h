#pragma once

#include "GameStates/GameState.h"
#include "GameObject/MovableObjects/SquareBird.h"
#include "Utilities/Level.h"
#include <vector>
#include "Utilities/Consts.h"
#include <fstream>
#include <iostream>
#include <Utilities/StatusBar.h>


class GameController;
class GameOverState;
class WinnerState;

class PlayState : public GameState {
public:
	PlayState(GameOverState& gameOverState,GameController& controller,WinnerState& winnerState);
	void initLevels();
	void setBird(sf::Sprite);
	virtual void handleEvents(sf::Event event, sf::RenderWindow& window);
	virtual void update(sf::Time dt);
	virtual void draw(sf::RenderWindow& window);
	void increaseCurrLevel();
	sf::Vector2f getBirdPos();	

	void checkForUpdates(sf::Time timer);

private:
	sf::View m_view;
	Level m_level;
	std::vector<std::string> m_levels;
	int m_currentLevel;
	SquareBird m_bird;
	GameOverState& m_gameOverState;
	WinnerState& m_WinnerState;
	GameController& m_controller;
	StatusBar m_bar;
};