#include "EDITLABLE.h"
#include"..\Components\Gate.h"
#include "..\ApplicationManager.h"
#include"..\Components\Connection.h"
EDITLABLE::EDITLABLE(ApplicationManager* pApp) :Action(pApp)
{
	//a = pApp;
}

EDITLABLE::~EDITLABLE(void)
{
}

void EDITLABLE::ReadActionParameters()
{


}

void EDITLABLE::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string x;
	Component** z = pManager->get_CompList();
	string press;
	//Calculate the rectangle Corners
	pOut->PrintMsg("if you want to edit lable press 1 if you want to edit source press 2 if you want to edit destination press 3");
	press = pIn->GetSrting(pOut);
	pOut->ClearStatusBar();
	if (press == "1")
	{
		for (int i = 0; i < pManager->get_compcount(); i++)
		{
			if (z[i]->get_selected() == true) {
				//if (dynamic_cast<Gate*>(z[i])) {
				x = pIn->GetSrting(pOut);
				z[i]->setlable(x);
				z[i]->drawlable(pOut, x, z[i]->get_GraphicsInfo().x2, z[i]->get_GraphicsInfo().y2);
				pOut->ClearDrawingArea();

			}

		}
	}
	else if (press == "2")
	{
		for (int i = 0; i < pManager->get_compcount(); i++)
		{
			OutputPin* pSrcPin;
			Connection* p;
			if (z[i]->get_selected() == true)
			{
				p = dynamic_cast<Connection*>(z[i]);
				if (p != NULL)
				{
					pSrcPin = p->getSourcePin();
					p->setSourcePin(pSrcPin);
					pManager->UpdateInterface();
					break;
				}
			}

		}
	}
	else if (press == "3")
	{
		for (int i = 0; i < pManager->get_compcount(); i++)
		{
			InputPin* DstPin;
			Connection* p;
			if (z[i]->get_selected() == true)
			{
				p = dynamic_cast<Connection*>(z[i]);
				if (p != NULL)
				{
					DstPin = p->getDestPin();
					p->setDestPin(DstPin);
					pManager->UpdateInterface();
					break;
				}

			}
		}
	}
}
void EDITLABLE::Undo()
{}

void EDITLABLE::Redo()
{}

