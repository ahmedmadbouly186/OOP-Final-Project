#include "AddXNOR2.h"
#include "..\ApplicationManager.h"

AddXNOR2::AddXNOR2(ApplicationManager* pApp) :Action(pApp)
{

}
AddXNOR2::~AddXNOR2(void)
{

}
void AddXNOR2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input XNOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddXNOR2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string x;
	//Calculate the rectangle Corners
	int Len = UI.XNOR2_Width;
	int Wdth = UI.XNOR2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the XNOR2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	if (GInfo.x1 > 0 && GInfo.x2<UI.width && GInfo.y1>UI.ToolBarHeight && GInfo.y2 < (UI.height - UI.StatusBarHeight))
	{
		XNOR2* pA = new XNOR2(GInfo, AND2_FANOUT,pManager->get_counter());
		pManager->AddComponent(pA);
		x = pIn->GetSrting(pOut);
		pA->setlable(x);
		pA->drawlable(pOut, x, GInfo.x2, GInfo.y2);
	}
	
}

void AddXNOR2::Undo()
{}

void AddXNOR2::Redo()
{}
