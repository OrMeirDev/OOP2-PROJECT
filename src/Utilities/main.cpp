#include "Utilities/GameController.h"
int main()
{
	try {
		GameController game;
		game.launch();
	}
	catch (std::runtime_error e)
	{
		std::cout << e.what() << std::endl;
	}
	
}
