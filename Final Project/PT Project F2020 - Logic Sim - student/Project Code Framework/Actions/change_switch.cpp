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
	ReadActionParameters();
	///////////////////////////////////
	Component* comp = pManager->ComponentRegion(Cx, Cy);
	switch_key* key = dynamic_cast<switch_key*>(comp);
	if (key != NULL)
	{
		bool c = key->get_close();
		c = (c == false) ? true : false;
		key->set_close(c);
	}
}
void change_switch::Undo()
{}

void change_switch::Redo()
{}
change_switch::~change_switch(void)
{
}