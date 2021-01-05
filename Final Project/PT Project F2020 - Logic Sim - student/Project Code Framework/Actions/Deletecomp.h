#pragma once
#include "action.h"
class Deletecomp : public Action
{
public:
	Deletecomp(ApplicationManager* pApp);
	virtual ~Deletecomp(void);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

