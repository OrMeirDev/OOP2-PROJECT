#pragma once

#include "Command.h"

class GameController;

class ExitGameCommand : public Command {
public:
	ExitGameCommand(GameController& controller);
	virtual void execute();
private:
	GameController& m_controller;

};