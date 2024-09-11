#include "GameStates/GameOverState.h"
#include "Utilities/GameController.h"
#include <memory>
#include "Commands/ChangeScreenCommand.h"

//----------------------------------------------------------------------------
GameOverState::GameOverState(MenuState& menuState,GameController& controller):m_menuState(menuState),
m_backToMenuButton(std::make_unique<ChangeScreenCommand>(controller, menuState), ResourceManager::instance().getTexture(BACKTOMENU_TEXTURE), sf::Vector2f(0, 0))
{
}
//----------------------------------------------------------------------------
void GameOverState::handleEvents(sf::Event event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
		sf::Vector2f pos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
		m_backToMenuButton.handleClick(pos);
	}
}
//----------------------------------------------------------------------------
void GameOverState::update(sf::Time dt)
{

}
//----------------------------------------------------------------------------
void GameOverState::draw(sf::RenderWindow& window)
{
	sf::Sprite helpState;
	helpState.setTexture(ResourceManager::instance().getTexture(GAMEOVER_TEXTURE));
	window.draw(helpState);
	m_backToMenuButton.draw(window);
}
//----------------------------------------------------------------------------