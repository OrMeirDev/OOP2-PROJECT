#include "GameStates/WinnerState.h"
#include "Utilities/GameController.h"
#include <memory>
#include "Commands/ChangeScreenCommand.h"

//----------------------------------------------------------------------------
WinnerState::WinnerState(MenuState& menuState, GameController& controller) :m_menuState(menuState),
m_backToMenuButton(std::make_unique<ChangeScreenCommand>(controller, menuState), ResourceManager::instance().getTexture(BACKTOMENU_TEXTURE), sf::Vector2f(0, 0))
{
}
//----------------------------------------------------------------------------
void WinnerState::handleEvents(sf::Event event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
		sf::Vector2f pos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
		m_backToMenuButton.handleClick(pos);
	}
}
//----------------------------------------------------------------------------
void WinnerState::update(sf::Time dt)
{

}
//----------------------------------------------------------------------------
void WinnerState::draw(sf::RenderWindow& window)
{
	sf::Sprite winnerState;
	winnerState.setTexture(ResourceManager::instance().getTexture(WINNER_TEXTURE));
	window.draw(winnerState);
	m_backToMenuButton.draw(window);
}
