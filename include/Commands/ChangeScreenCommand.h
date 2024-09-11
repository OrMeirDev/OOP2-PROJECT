#pragma once

#include "Command.h"

class GameController;
class GameState;

class ChangeScreenCommand : public Command {
public:
	ChangeScreenCommand(GameController& controller, GameState& nextState);
	virtual void execute();
private:
	GameController& m_controller;
	GameState& m_nextState;
};