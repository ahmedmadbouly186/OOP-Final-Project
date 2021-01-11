#pragma once
#include"Action.h"
class SIM_Tool :public Action
{
public:
	SIM_Tool(ApplicationManager* pApp);
	virtual ~SIM_Tool(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

