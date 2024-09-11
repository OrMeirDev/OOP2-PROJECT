#include "Commands/ChangeScreenCommand.h"

#include "Utilities/GameController.h"
#include "GameStates/GameState.h"

ChangeScreenCommand::ChangeScreenCommand(GameController& controller, GameState& nextState):m_controller(controller),m_nextState(nextState)
{
}

void ChangeScreenCommand::execute()
{
	m_controller.changeGameState(m_nextState);
}
