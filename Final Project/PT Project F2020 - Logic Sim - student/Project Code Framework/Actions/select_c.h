#pragma once
#include "action.h"
class select_c : public Action
{
private:
	int Cx, Cy;	//Center point of the gate
	
public:
	select_c(ApplicationManager* pApp);
	virtual ~select_c(void);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();
};

