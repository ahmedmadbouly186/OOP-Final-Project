#include "change_switch.h"
#include "..\ApplicationManager.h"
change_switch::change_switch(ApplicationManager* pApp) :Action(pApp)
{
}
void change_switch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click on the Key you want to Change");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}
void change_switch::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	///////////////////////////////////
	int count = pManager->get_compcount();
	Component** x = pManager->get_CompList();
	for (int i = 0; i < count; i++)
	{
		Component* y = x[i];
		GraphicsInfo t = y->get_GraphicsInfo();
		if ((Cx > t.x1 && Cx < t.x2) && (Cy > t.y1 && Cy < t.y2))
		{
			switch_key* key = dynamic_cast<switch_key*>(y);
			if (key != NULL)
			{
				bool c = key->get_close();
				c = (c == false) ? true : false;
				key->set_close(c);
			}
			break;
		}
	}
}
void change_switch::Undo()
{}

void change_switch::Redo()
{}
change_switch::~change_switch(void)
{
}