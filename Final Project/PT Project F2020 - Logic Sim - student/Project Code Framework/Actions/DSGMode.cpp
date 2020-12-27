#include "DSGMode.h"
#include "..\ApplicationManager.h"


DSGMode::DSGMode(ApplicationManager* pApp):Action(pApp)
{

}

DSGMode:: ~DSGMode(void)
{

}

//Reads parameters required for action to execute
void DSGMode::ReadActionParameters()
{

}

//Execute action (code depends on action type)
void DSGMode::Execute()
{
	pManager->GetOutput()->CleartoolbarArea1();
	pManager->GetOutput()->CreateDesignToolBar();
}


void DSGMode:: Undo()
{

}


void DSGMode:: Redo()
{

}
