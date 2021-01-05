#pragma once
#include "Action.h"
class load : public Action 
{
private:

public:
	load(ApplicationManager* pApp);
	virtual ~load(void);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

