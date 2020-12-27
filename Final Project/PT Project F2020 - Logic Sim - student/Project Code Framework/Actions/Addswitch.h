#pragma once
#include "action.h"
#include "..\Components\switch_key.h"
class Addswitch : public Action
{
private:
	int Cx, Cy;
	int x1, y1, x2, y2;
public:
	Addswitch(ApplicationManager* pApp);
	virtual ~Addswitch(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
};

