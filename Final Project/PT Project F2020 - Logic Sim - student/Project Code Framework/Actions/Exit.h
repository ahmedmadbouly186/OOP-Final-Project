#pragma once

#include "action.h"

class exist :public Action
{

private:
	bool b;	
public:
	exist(ApplicationManager* pApp);
	virtual ~exist(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

