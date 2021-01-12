#include "Copy.h"
#include "..\ApplicationManager.h"

Copy::Copy(ApplicationManager* pApp) :Action(pApp)
{
}
void Copy::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on the component you want to copy");

	
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Copy::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	/*int count = pManager->get_compcount();
	Component** x = pManager->get_CompList();

	for (int i = 0; i < count; i++)
	{
		Component* y = x[i];
		if (y->get_selected() == true)
		{
			y->setcopy(1);
			break;
		}
	}
}*/
	Output* pOut = pManager->GetOutput();
	Component* x = pManager->get_selected();
	if (x != NULL) {
		pManager->setcut_component(NULL);
		x->setcopy(1);
		pOut->PrintMsg("componnent copied");
	}
}

void Copy::Undo()
{
}

void Copy::Redo()
{
}
Copy::~Copy(void)
{
}