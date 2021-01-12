#pragma once
#include "Action.h"

class Cut :public Action
{
private:

public:
	Cut(ApplicationManager* pApp);
	virtual ~Cut(void);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};

