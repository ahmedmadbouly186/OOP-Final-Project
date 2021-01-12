#pragma once

#include "action.h"

class statusbar :public Action
{

private:
	//Parameters for rectangular area to be occupied by the gate
public:
	statusbar(ApplicationManager* pApp);
	virtual ~statusbar(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

