#include "AddLEDgate.h"
#include "..\ApplicationManager.h"
AddLEDgate::AddLEDgate(ApplicationManager* pApp) :Action(pApp)
{
}

AddLEDgate::~AddLEDgate(void)
{
}

void AddLEDgate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("LED Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLEDgate::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string x;
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	if (GInfo.y1 > UI.ToolBarHeight && GInfo.y2 < UI.height - UI.StatusBarHeight && GInfo.x1 > 0 && GInfo.x2 < UI.width)
	{
		LED* pA = new LED(GInfo, pManager->get_counter());
		pManager->AddComponent(pA);
		x = pIn->GetSrting(pOut, GInfo.x2, GInfo.y2);
		pA->setlable(x);

	}
}

void AddLEDgate::Undo()
{}

void AddLEDgate::Redo()
{}

