#pragma once

#include "GameState.h"
#include "Utilities/Button.h"
#include <vector>
#include <SFML/Audio.hpp>


class GameController;
class PlayState;
class HelpState;

class MenuState : public GameState {
public:
	MenuState(PlayState& playState, HelpState& helpState, GameController& controller);
	virtual void handleEvents(sf::Event event, sf::RenderWindow& window);
	virtual void update(sf::Time dt);
	virtual void draw(sf::RenderWindow& window);
private:
	sf::Sprite m_newGameButton;
	sf::Sprite m_helpButton;
	sf::Sprite m_exitButton;
	sf::Sprite m_backGround;
	sf::Sprite m_backToMenu;

	std::vector<Button> m_buttons;

	PlayState& m_playState;
	HelpState& m_helpState;
	sf::Music m_music;

};