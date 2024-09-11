#include <SFML/Graphics.hpp>
#include "Utilities/Consts.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <SFML/Audio.hpp>
#include "Utilities/ResourceManager.h"
#include "Utilities/GameController.h"
#include "Utilities/CollisonHandlers.h"

//-----------------------------------------------------------------------------------------------------------
GameController::GameController():m_menuState(m_playState,m_helpState,*this),m_helpState(m_menuState,*this),m_gameOverState(m_menuState,*this),
                                 m_playState(m_gameOverState,*this,m_winnerState),m_winnerState(m_menuState,*this),
	m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Square Bird", sf::Style::Close | sf::Style::Titlebar)
{
	addAllCollisions();
	m_currentState = &m_menuState;
}
//-----------------------------------------------------------------------------------------------------------
void GameController::launch()
{
	sf::Clock clock;
	m_window.setFramerateLimit(240);

	while (m_window.isOpen()) {
		sf::Event event;
		while (m_window.pollEvent(event)) {
			// To handle events
			if (event.type == sf::Event::Closed) {
				m_window.close();
			}
			m_currentState->handleEvents(event, m_window);
		}
		// To Update
		sf::Time dt = clock.restart();
		m_currentState->update(dt);

		m_window.clear();
		// TO DRAW
		m_currentState->draw(m_window);
		m_window.display();
	}
}
//-----------------------------------------------------------------------------------------------------------
void GameController::gameOver()
{
	m_currentState = &m_gameOverState;
}
//-----------------------------------------------------------------------------------------------------------
void GameController::winner()
{
	m_currentState = &m_winnerState;
}
//-----------------------------------------------------------------------------------------------------------
void GameController::changeGameState(GameState& state)
{
	m_currentState = &state;
}
//-----------------------------------------------------------------------------------------------------------
void GameController::closeGame()
{
	m_window.close();
}
//-----------------------------------------------------------------------------------------------------------