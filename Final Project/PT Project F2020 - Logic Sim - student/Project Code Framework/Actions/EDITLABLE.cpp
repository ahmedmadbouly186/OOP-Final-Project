#include "EDITLABLE.h"
#include "..\ApplicationManager.h"

EDITLABLE::EDITLABLE(ApplicationManager* pApp) :Action(pApp)
{
	a = pApp;
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
	Component** z = a->get_CompList();
	//Calculate the rectangle Corners
	for (int i = 0; i < a->get_compcount(); i++)
	{
		if (z[i]->get_selected() == true) {
			x = pIn->GetSrting(pOut, z[i]->get_GraphicsInfo().x2, z[i]->get_GraphicsInfo().y2);
			z[i]->setlable(x);
		}
	}
}
void EDITLABLE::Undo()
{}

void EDITLABLE::Redo()
{}

