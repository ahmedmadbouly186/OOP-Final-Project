#include "Addswitch.h"
#include "..\ApplicationManager.h"

Addswitch::Addswitch(ApplicationManager* pApp) :Action(pApp)
{
}

Addswitch::~Addswitch(void)
{
}

void Addswitch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("switch: Click to add the switch");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Addswitch::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string x;
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the switch

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	if (GInfo.x1 > 0 && GInfo.x2<UI.width && GInfo.y1>UI.ToolBarHeight && GInfo.y2 < (UI.height - UI.StatusBarHeight))
	{
		switch_key* pA = new switch_key(GInfo, AND2_FANOUT,pManager->get_counter());
		pManager->AddComponent(pA);
		x = pIn->GetSrting(pOut);
		pA->setlable(x);
		pA->drawlable(pOut, x, GInfo.x2, GInfo.y2);
	}
	
}

void Addswitch::Undo()
{}

void Addswitch::Redo()
{}

