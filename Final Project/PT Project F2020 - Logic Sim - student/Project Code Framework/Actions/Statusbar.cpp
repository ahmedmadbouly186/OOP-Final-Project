#include "Statusbar.h"
#include "..\ApplicationManager.h"



statusbar::statusbar(ApplicationManager* pApp) :Action(pApp)
{
}

statusbar::~statusbar(void)
{
}

void statusbar::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("click on the Status Bar, Click anywhere to continue ");

	//Wait for User Input
	int x = 0; int y = 0;
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void statusbar::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	
}

void statusbar::Undo()
{}

void statusbar::Redo()
{}
