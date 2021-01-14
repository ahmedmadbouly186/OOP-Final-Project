#include "SIMMODE.h"
#include "..\ApplicationManager.h"
#include "..\Components\Connection.h"
#include "..\Components\Gate.h"
#include "..\Components\LED.h"
#include "..\Components\switch_key.h"
#include "Action.h"
#include "..\Components\InputPin.h"
#include "..\Components\OutputPin.h"
#include <iostream>
using namespace std;
SIMMODE::SIMMODE(ApplicationManager* pApp) :Action(pApp)
{
}

SIMMODE::~SIMMODE(void)
{
}

void SIMMODE::ReadActionParameters()
{
	
}

void SIMMODE::Execute()
{
	// change from menubar to simbar
	ReadActionParameters();
	Output* pout;
	pout = pManager->GetOutput();
	pout->CleartoolbarArea1();
	pout->CreateSimulationToolBar();
	pout->ClearStatusBar();
	// the actually code that make the circut behave correctly
	pManager->operations();
}

void SIMMODE::Undo()
{}

void SIMMODE::Redo()
{}

