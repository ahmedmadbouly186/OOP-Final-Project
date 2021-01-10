#include "ADD_XOR_GATE_3.h"
#include "..\ApplicationManager.h"

ADDXORGATE3::ADDXORGATE3(ApplicationManager* pApp) :Action(pApp)
{
}

ADDXORGATE3::~ADDXORGATE3(void)
{
}

void ADDXORGATE3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3-Input XOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void ADDXORGATE3::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string x;
	//Calculate the rectangle Corners
	int Len = UI.XOR3_Width;
	int Wdth = UI.XOR3_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the XOR3 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	if (GInfo.y1 > UI.ToolBarHeight && GInfo.y2 < UI.height - UI.StatusBarHeight && GInfo.x1 > 0 && GInfo.x2 < UI.width)
	{

		XOR3* pA = new XOR3(GInfo, AND2_FANOUT, pManager->get_counter());
		pManager->AddComponent(pA);
		x = pIn->GetSrting(pOut);
		pA->setlable(x);
		pA->drawlable(pOut, x, GInfo.x2, GInfo.y2);
	}
	//XOR3* pA = new XOR3(GInfo, AND2_FANOUT);
	//pManager->AddComponent(pA);
}

void ADDXORGATE3::Undo()
{}

void ADDXORGATE3::Redo()
{}


