#pragma once
#include "Action.h"

class Copy :public Action
{
private:

public:
	Copy(ApplicationManager* pApp);
	virtual ~Copy(void);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};

