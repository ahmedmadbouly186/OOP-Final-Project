#include "Exit.h"
#include "..\ApplicationManager.h"
#include "Save.h"



exist::exist(ApplicationManager* pApp) :Action(pApp)
{
}

exist::~exist(void)
{
}

void exist::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string check;
	//Print Action Message
	pOut->PrintMsg("click on the Exist, if you want to save befor closing enter 1 ,else enter 2 ");
	do {
		check = pIn->GetSrting(pOut,true);
		if (check == "1")
		{
			b = true;
		}
		else if (check == "2")
		{
			b = false;
		}
		else
		{
			pOut->PrintMsg("valid number ,please type 1 or 2 only ");
		}
	} while ((check != "1") &&( check != "2"));


	
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void exist::Execute()
{
	ReadActionParameters();
	if (b == true)
	{
		pManager->ExecuteAction(SAVE);
	}


}

void exist::Undo()
{}

void exist::Redo()
{}
