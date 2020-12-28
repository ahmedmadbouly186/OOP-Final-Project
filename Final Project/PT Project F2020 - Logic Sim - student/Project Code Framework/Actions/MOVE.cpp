#include "MOVE.h"
#include "..\ApplicationManager.h"

Move::Move(ApplicationManager* pApp) :Action(pApp)
{

}
void Move::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on the component you want to move");

	//Wait for User Input
	pOut->PrintMsg("Click on place you want to move component to");

	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Move::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	int count = pManager->get_compcount();
	Component** x = pManager->get_CompList();
	for (int i = 0; i < count; i++)
	{
		Component* y = x[i];
		GraphicsInfo t = y->get_GraphicsInfo();
		if (y->get_selected() == true)
		{
			GraphicsInfo m;
			m.x1 = Cx - UI.AND2_Width;
			m.y1 = Cy - UI.AND2_Width;
			m.x2 = Cx + UI.AND2_Width;
			m.y2 = Cx + UI.AND2_Width;
			y->set_GraphicsInfo(m);
			break;
		}
	}
}

void Move::Undo()
{
}

void Move::Redo()
{
}
Move::~Move(void)
{
}