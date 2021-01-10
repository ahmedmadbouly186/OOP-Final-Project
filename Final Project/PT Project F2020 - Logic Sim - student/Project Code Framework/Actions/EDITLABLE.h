#pragma once
#include "Action.h"
#include "..\Components\Component.h"
class EDITLABLE : public Action
{
	private:
		//Parameters for rectangular area to be occupied by the gate
		int Cx, Cy;	//Center point of the gate
		int x1, y1, x2, y2;	//Two corners of the rectangluar area
		//ApplicationManager *a;
	public:
		EDITLABLE(ApplicationManager * pApp);
		virtual ~EDITLABLE(void);

		//Reads parameters required for action to execute
		virtual void ReadActionParameters();
		//Execute action (code depends on action type)
		virtual void Execute();

		virtual void Undo();
		virtual void Redo();


};

