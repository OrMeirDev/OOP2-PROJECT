#include "GameStates/HelpState.h"
#include "Utilities/GameController.h"
#include "GameStates/MenuState.h"
#include <memory>
#include "Utilities/GameController.h"
#include "Commands/ChangeScreenCommand.h"

HelpState::HelpState(MenuState& menuState,GameController& controller):m_menuState(menuState),
m_backToMenuButton(std::make_unique<ChangeScreenCommand>(controller, menuState), ResourceManager::instance().getTexture(BACKTOMENU_TEXTURE), sf::Vector2f(0, 0))
{}
//-----------------------------------------------------------------
void HelpState::update(sf::Time dt)
{
}

//-------------------------------------------------------------------
void HelpState::handleEvents(sf::Event event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
		sf::Vector2f pos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
		m_backToMenuButton.handleClick(pos);
		
	}
}
//----------------------------------------------------------------
void HelpState::draw(sf::RenderWindow& window)
{
	sf::Sprite helpState;
	helpState.setTexture(ResourceManager::instance().getTexture(HELPSCREEN_TEXTURE));
	window.draw(helpState);
	m_backToMenuButton.draw(window);
}
