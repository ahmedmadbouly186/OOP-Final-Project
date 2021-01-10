#include "AddNANDgate2.h"
#include "..\ApplicationManager.h"
AddNANDgate2::AddNANDgate2(ApplicationManager* pApp) :Action(pApp)
{
}

AddNANDgate2::~AddNANDgate2(void)
{
}

void AddNANDgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input NAND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddNANDgate2::Execute()
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
	if (GInfo.x1 > 0 && GInfo.x2<UI.width && GInfo.y1>UI.ToolBarHeight && GInfo.y2 < (UI.height - UI.StatusBarHeight))
	{
		 NAND2* pA = new NAND2(GInfo, AND2_FANOUT, pManager->get_counter());
		pManager->AddComponent(pA);
		x = pIn->GetSrting(pOut);
		pA->setlable(x);
		pA->drawlable(pOut, x, GInfo.x2, GInfo.y2);
	}
}

void AddNANDgate2::Undo()
{}

void AddNANDgate2::Redo()
{}

