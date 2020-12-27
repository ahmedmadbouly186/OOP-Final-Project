#include "AddGate.h"
#include "..\ApplicationManager.h"
AddGate::AddGate(ApplicationManager* pApp) :Action(pApp)
{
}

AddGate::~AddGate(void)
{
}

void AddGate::ReadActionParameters()
{
	//Get a Pointer to the Output Interfaces
	//pout = pManager->GetOutput();
}

void AddGate::Execute()
{
	//ReadActionParameters();
	Output* pout;
	pout = pManager->GetOutput();
	pout->CleartoolbarArea1();
	pout->CreateDesignToolBar2();

}

void AddGate::Undo()
{}

void AddGate::Redo()
{}

