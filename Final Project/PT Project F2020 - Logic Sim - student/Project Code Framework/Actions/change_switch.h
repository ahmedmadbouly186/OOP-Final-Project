#pragma once
#include "action.h"
#include "Addswitch.h"
class change_switch : public Action
{
private:
	int Cx, Cy;	//Center point of the gate
public:
	change_switch(ApplicationManager* pApp);
	virtual ~change_switch(void);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

