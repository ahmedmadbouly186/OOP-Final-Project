#pragma once

#include "action.h"



class dsntool :public Action
{

private:
	//Parameters for rectangular area to be occupied by the gate
	
public:
	dsntool(ApplicationManager* pApp);
	virtual ~dsntool(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

