#pragma once
#include "action.h"


class DSGMode :public Action
{

private:

public:
	DSGMode(ApplicationManager* pApp);
	virtual ~DSGMode(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};


