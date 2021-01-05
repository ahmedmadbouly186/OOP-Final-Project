#include "select_c.h"
#include "..\ApplicationManager.h"
select_c::select_c(ApplicationManager* pApp) :Action(pApp)
{
	
}
void select_c::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on the component you want to select");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void select_c::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
	int count = pManager->get_compcount();
	Component* y = pManager->ComponentRegion(Cx, Cy);
	if (y != NULL)
	{
		bool c = y->get_selected();
		c = (c == false) ? true : false;
		y->set_selected(c);

	}
	/*int count = pManager->get_compcount();
	Component** x = pManager->get_CompList();
	for (int i = 0; i < count; i++)
	{
		Component* y = x[i];
		GraphicsInfo t = y->get_GraphicsInfo();
		if ((Cx > t.x1 && Cx < t.x2) && (Cy > t.y1 && Cy < t.y2))
		{
			bool c = y->get_selected();
			c = (c == false) ? true: false;
			y->set_selected(c);
			break;
		}
	}*/
}

void select_c::Undo()
{
}

void select_c::Redo()
{
}
select_c::~select_c(void)
{
}