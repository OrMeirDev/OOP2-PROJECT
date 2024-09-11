#include "GameStates/PlayState.h"
#include "Utilities/CollisionManager.h"
#include "GameStates/GameOverState.h"
#include "GameStates/WinnerState.h"
#include "Utilities/GameController.h"

//----------------------------------------------------------------------------
PlayState::PlayState(GameOverState& gameOverState,GameController& controller,WinnerState& winnerState):m_level(*this),m_currentLevel(0),
                                                                              m_gameOverState(gameOverState),m_controller(controller),
	                                                                          m_bird(m_level,*this),m_WinnerState(winnerState),m_bar(m_bird)
{
	m_view.setSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	m_view.setCenter(m_bird.getPosition());
	initLevels();
}
//----------------------------------------------------------------------------
void PlayState::initLevels()
{
	m_levels.clear();
	std::ifstream input("Playlist.txt");
	if (!input) {
		throw (std::runtime_error("Couldnt open levels file!"));
	}
	int size;
	input >> size;
	for (int i = 1; i <= size; i++) {
		std::string levelName = "Level" + std::to_string(i) + ".txt";
		m_levels.push_back(levelName);
	}
	input.close();

	m_level.loadLevel(m_levels[m_currentLevel]);
}
//----------------------------------------------------------------------------
void PlayState::setBird(sf::Sprite sprite)
{
	m_bird.setSprite(sprite);
	m_bird.setStartingPosition(sprite.getPosition());
}
//----------------------------------------------------------------------------
void PlayState::handleEvents(sf::Event event, sf::RenderWindow& window){
	m_bird.handleEvent(event);
}
//----------------------------------------------------------------------------
void PlayState::update(sf::Time timer) // Moving Objects
{
	float dt = timer.asSeconds();
	m_bird.update(dt);
	checkForUpdates(timer);

	m_level.handleCollisions(m_bird);
}
//----------------------------------------------------------------------------
void PlayState::draw(sf::RenderWindow& window) // Drawing Objects
{
	sf::Vector2f viewCenter(m_bird.getPosition().x - VIEWXMARGIN,WINDOW_HEIGHT/2);

	m_view.setCenter(viewCenter);
	window.setView(m_view);

	m_level.draw(window);
	m_bird.render(window);
	m_bar.draw(window);

	window.setView(window.getDefaultView());
}
//----------------------------------------------------------------------------
void PlayState::increaseCurrLevel()
{
	if (m_currentLevel + 1 < m_levels.size())
	{
		m_currentLevel++;
		m_level.loadLevel(m_levels[m_currentLevel]);
		m_bird.setPosition(m_bird.getStartingPos());
	}
	else{
		m_controller.winner();
		m_bird.setLives(LIVES);
		m_bird.resetCoins();
		m_level.resetAllData();
		m_currentLevel = 0;
		initLevels();
	}
}
//----------------------------------------------------------------------------
sf::Vector2f PlayState::getBirdPos()
{
	return m_bird.getPosition();
}
//----------------------------------------------------------------------------
void PlayState::checkForUpdates(sf::Time timer)
{
	if (m_bird.getRemainingLives() == 0)
	{
		m_controller.gameOver();
		m_bird.resetCoins();
		m_bird.setLives(LIVES);
		m_currentLevel = 0;
		m_level.resetAllData();
		initLevels();
		
	}

	sf::Vector2f backgroundPos = m_bird.getPosition();
	float backgroundX = backgroundPos.x -= MARGIN;
	float backgroundY = 0;

	m_level.update(timer, backgroundX, backgroundY, m_bird.getPosition().x);

	if (m_bird.getPosition().y > YBORDER)
	{
		m_bird.reduceLifeAndClearBlocks();
		m_bird.setPosition(m_bird.getStartingPos());
		std::cout << m_bird.getRemainingLives();
	}
}