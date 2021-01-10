#pragma once
#include"Copy.h"
#include "Action.h"
class Paste :	public Action 
{
private:
	int Cx, Cy;	//Center point of the gate

public:
	Paste(ApplicationManager* pApp);
	virtual ~Paste(void);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undo();
	virtual void Redo();

};

