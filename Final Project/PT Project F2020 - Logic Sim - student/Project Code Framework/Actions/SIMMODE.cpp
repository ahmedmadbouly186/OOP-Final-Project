#include "SIMMODE.h"
#include "..\ApplicationManager.h"
SIMMODE::SIMMODE(ApplicationManager* pApp) :Action(pApp)
{
}

SIMMODE::~SIMMODE(void)
{
}

void SIMMODE::ReadActionParameters()
{
	//Get a Pointer to the Output Interfaces
	//pout = pManager->GetOutput();


}

void SIMMODE::Execute()
{
	ReadActionParameters();
	Output* pout;
	pout = pManager->GetOutput();
	pout->CleartoolbarArea1();
	pout->CreateSimulationToolBar();
}

void SIMMODE::Undo()
{}

void SIMMODE::Redo()
{}

