#pragma once
#include "Action.h"


class Move :public Action
{
private:
	int Cx, Cy;	//Center point of the gate

public:
	Move(ApplicationManager* pApp);
	virtual ~Move(void);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};


