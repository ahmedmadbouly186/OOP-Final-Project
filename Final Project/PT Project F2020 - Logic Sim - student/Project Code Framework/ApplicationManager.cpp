#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\ADD_XOR_GATE_3.h"
#include "Actions\AddBuff.h"
#include "Actions\AddNORgate3.h"
#include "Actions\AddConnection.h"
#include "Actions\DSGMode.h"
#include "Actions\AddGate.h"
#include "Actions\Addswitch.h"
#include "Actions\AddXNOR2.h"
#include "Actions\AddXOR2.h"
#include "Actions\change_switch.h"
#include "Actions/select_c.h"
#include "Actions/Close.h"
#include"Actions/SIMMODE.h"
#include "Actions/AddINVgate.h"
#include "Actions/AddNANDgate2.h"
#include "Actions/AddNORgate2.h"


ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;
		case ADD_Buff:
			pAct = new AddBuff(this);
			break;
		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);
			break;
		case ADD_CONNECTION:
			pAct = new AddConnection(this);
			break;
		case DSN_MODE:
			pAct = new DSGMode(this);
			break;
		case ADD_XOR_GATE_3:
			pAct = new ADDXORGATE3(this);
			break;
		case ADD_XNOR_GATE_2:
			pAct = new AddXNOR2(this);
			break;
		case ADD_XOR_GATE_2:
			pAct = new AddXOR2(this);
			break;
		case ADD_Switch:
			pAct = new Addswitch(this);
			break;
		case Change_Switch:
			pAct = new change_switch(this);
			break;
		case SELECT:
			pAct = new select_c(this);
			break;
		case ADD_Gate:
			pAct = new AddGate(this);
			break;
		case close:
			pAct = new Close(this);
			break;
		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;

		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;

		case ADD_INV:
			pAct = new AddINVgate(this);
			break;
		case SIM_MODE:
			pAct = new SIMMODE(this);
			break;
		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);

}
int ApplicationManager::get_compcount()
{
	return CompCount;
}
Component**& ApplicationManager::get_CompList()
{
	Component** x = this->CompList;
	return x;
}
////////////////////////////////////////////////////////////////////
Component* ApplicationManager::ComponentRegion(int x,int y) {
	for (int i = 0; i < CompCount; i++) {
		Component* p = CompList[i]->ComponentRegion(x, y);
		if (p != NULL){
			Gate* g = dynamic_cast<Gate*>(p);
			if (g != NULL) {
				return g;
			}
		}
	}
	return NULL;
	}

////////////////////////////////////////////////////////////////////

Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}