#include "DSG_TOOL.h"
#include "..\ApplicationManager.h"



dsntool::dsntool(ApplicationManager* pApp) :Action(pApp)
{
}

dsntool::~dsntool(void)
{
}

void dsntool::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("click on empty area in the Design Tool Bar, Click anywhere to continue ");

	//Wait for User Input
	int x = 0; int y = 0;
	pIn->GetPointClicked(x, y);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void dsntool::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string x;
	

	
}

void dsntool::Undo()
{}

void dsntool::Redo()
{}
