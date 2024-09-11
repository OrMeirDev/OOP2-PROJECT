#include "GameStates/MenuState.h"
#include "Utilities/ResourceManager.h"
#include "Utilities/Consts.h"
#include "GameStates/PlayState.h"
#include "GameStates/HelpState.h"
#include <memory>
#include "Commands/ExitGameCommand.h"
#include "Commands/ChangeScreenCommand.h"
//----------------------------------------------------------------------------
MenuState::MenuState(PlayState& playState,HelpState& helpState,GameController& controller) :m_playState(playState),m_helpState(helpState)
{
	m_backGround.setTexture(ResourceManager::instance().getTexture(BACKGROUND_TEXTURE));
	m_backGround.setPosition(sf::Vector2f(0, 0));
	
	m_buttons.emplace_back(std::make_unique<ChangeScreenCommand>(controller,playState), ResourceManager::instance().getTexture(NEWGAME_TEXTURE),  sf::Vector2f(900, 100));
	m_buttons.emplace_back(std::make_unique<ChangeScreenCommand>(controller, helpState), ResourceManager::instance().getTexture(HELP_TEXTURE),  sf::Vector2f(900, 200));
	m_buttons.emplace_back(std::make_unique<ExitGameCommand>(controller), ResourceManager::instance().getTexture(EXIT_TEXTURE), sf::Vector2f(900, 300));
	m_music.openFromFile(MENU_SOUND);
	m_music.setVolume(30);
	m_music.setLoop(true);
	m_music.play();

}
//----------------------------------------------------------------------------
void MenuState::handleEvents(sf::Event event, sf::RenderWindow& window)
{	
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
		sf::Vector2f pos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
		std::for_each(m_buttons.begin(), m_buttons.end(), [pos](Button& button) {button.handleClick(pos); });
	}
	if (event.type == sf::Event::MouseMoved)
	{
		sf::Event::MouseMoveEvent  tempevent = event.mouseMove;
		sf::Vector2f pos = window.mapPixelToCoords({ tempevent.x, tempevent.y });
		std::for_each(m_buttons.begin(), m_buttons.end(), [pos](Button& button) {button.handleHover(pos); });
	}
}
//----------------------------------------------------------------------------
void MenuState::update(sf::Time dt)
{
}
//----------------------------------------------------------------------------
void MenuState::draw(sf::RenderWindow& window)
{
	window.draw(m_backGround);
	std::for_each(m_buttons.begin(), m_buttons.end(), [&window](Button& button) {button.draw(window); });
}
//----------------------------------------------------------------------------