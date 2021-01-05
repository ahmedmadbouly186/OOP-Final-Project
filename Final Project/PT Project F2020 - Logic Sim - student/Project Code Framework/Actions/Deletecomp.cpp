#include "Deletecomp.h"
#include "..\ApplicationManager.h"
Deletecomp::Deletecomp(ApplicationManager* pApp) :Action(pApp)
{
	
}
void Deletecomp::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	//pOut->PrintMsg("Click on the component you want to select");

	//Wait for User Input
	//pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	//pOut->ClearStatusBar();

}

void Deletecomp::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	pManager->Delete();

	/*int count = pManager->get_compcount();
	Component* y = pManager->ComponentRegion(Cx, Cy);
	if (y != NULL)
	{
		bool c = y->get_selected();
		c = (c == false) ? true : false;
		y->set_selected(c);

	}*/
}

void Deletecomp::Undo()
{
}

void Deletecomp::Redo()
{
}
Deletecomp::~Deletecomp(void)
{
}