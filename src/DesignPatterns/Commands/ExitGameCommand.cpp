#include "Commands/ExitGameCommand.h"

#include "Utilities/GameController.h"

ExitGameCommand::ExitGameCommand(GameController& controller):m_controller(controller)
{
}

void ExitGameCommand::execute()
{
	m_controller.closeGame();
}
