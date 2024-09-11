#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include "Level.h"

#include "GameStates/MenuState.h"
#include "GameStates/PlayState.h"
#include "GameStates/GameState.h"
#include "GameStates/HelpState.h"
#include "GameStates/WinnerState.h"
#include "GameStates/GameOverState.h"

class Stats;
class Menu;

class GameController {
public:
	GameController();
	void launch();
	void gameOver();
	void winner();
	void changeGameState(GameState& state);
	void closeGame();
	
private:
	GameState* m_currentState;
	MenuState m_menuState;
	PlayState m_playState;
	HelpState m_helpState;
	WinnerState m_winnerState;
	GameOverState m_gameOverState;

	sf::RenderWindow m_window;
};