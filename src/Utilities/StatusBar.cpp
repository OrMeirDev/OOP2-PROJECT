#include "Utilities/StatusBar.h"
//----------------------------------------------------------------------------
StatusBar::StatusBar(SquareBird& bird):m_bird(bird)
{
	m_coin.setTexture(ResourceManager::instance().getTexture(COIN2_TEXTURE));
	m_lives.setTexture(ResourceManager::instance().getTexture(LIVES_TEXTURE));
	m_distance.setTexture(ResourceManager::instance().getTexture(DISTANCE_TEXTURE));

	m_lives.setPosition(410, 10);
	m_coin.setPosition(870, 20);
	m_distance.setPosition(610, 20);


}
//----------------------------------------------------------------------------
void StatusBar::draw(sf::RenderWindow& window)
{
	auto curr_view = window.getView();
	window.setView(window.getDefaultView());

	Stats stats = m_bird.getStats();

	sf::Text livesText;
	sf::Text distanceText;
	sf::Text coinsText;
	
	
	makeText(livesText, window.getView().getCenter().x - 180, m_lives.getPosition().y, stats.m_lives);
	makeText(distanceText,window.getView().getCenter().x+ 40, m_distance.getPosition().y - 10, stats.m_distance);
	makeText(coinsText, window.getView().getCenter().x +270, m_coin.getPosition().y -10, stats.m_coins);


	window.draw(livesText);
	window.draw(distanceText);
	window.draw(coinsText);
	window.draw(m_coin);
	window.draw(m_distance);
	window.draw(m_lives);

	window.setView(curr_view);

}
//----------------------------------------------------------------------------
void StatusBar::makeText(sf::Text& text, int x, int y, int num)
{
	text.setCharacterSize(FONTSINZE);
	text.setPosition(x, y);
	text.setFont(ResourceManager::instance().getFont());
	text.setString(std::to_string(num));
}
//----------------------------------------------------------------------------