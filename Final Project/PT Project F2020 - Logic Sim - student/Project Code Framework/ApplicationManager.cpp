#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddANDgate3.h"
#include "Actions\AddORgate2.h"

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
#include "Actions/SIMMODE.h"
#include "Actions/AddINVgate.h"
#include "Actions/AddNANDgate2.h"
#include "Actions/AddNORgate2.h"
#include "Actions/AddLEDgate.h"
#include "Actions/MOVE.h"
#include "Actions/Save.h"
#include "Actions/Deletecomp.h"
#include "Actions/load.h"
#include<iostream>
using namespace std;


ApplicationManager::ApplicationManager()
{
	CompCount = 0;
	counter = 0;

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
	for (int i = 0; i < CompCount; i++)
	{
		cout << CompList[i]->GetOutPinStatus() << endl;
	}
	counter++;
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
		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			break;
		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
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
		case DEL:
			pAct = new Deletecomp(this);
			break;
		case LOAD:
			pAct = new load(this);
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
		case ADD_LED:
			pAct = new AddLEDgate(this);
			break;
		case MOVE:
			pAct = new Move(this);
			break;
		case SAVE:
			pAct = new Save(this);
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
			return p;
		}
	}
	return NULL;
	}

////////////////////////////////////////////////////////////////////

Component* ApplicationManager::componentreturin(int i) {
	return 	CompList[i];

}
/////////////////////////
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
void ApplicationManager::save(ofstream& outputfile)
{
	outputfile << CompCount << endl;
	for (int i = 0; i < CompCount; i++)
	{
		Gate* gate = dynamic_cast<Gate*>(CompList[i]);
		if (gate != NULL)
		{
			CompList[i]->save(outputfile);
		}
		switch_key* Switch = dynamic_cast<switch_key*>(CompList[i]);
		if (Switch != NULL)
		{
			CompList[i]->save(outputfile);
		}
		LED* led = dynamic_cast<LED*>(CompList[i]);
		if (led != NULL)
		{
			CompList[i]->save(outputfile);
		}
	}
	outputfile << "connections" << endl;
	for (int i = 0; i < CompCount; i++)
	{
		Connection* connection1 = dynamic_cast<Connection*>(CompList[i]);
		if (connection1 != NULL)
		{
			CompList[i]->save(outputfile);
		}
	}
}
/////////////////////////////
//Delete
void ApplicationManager::Delete()
{
	for (int i = 0; i < CompCount; i++)
	{
		Component* p = CompList[i];
		if (p->get_selected() == true)
		{
			CompList[i] = CompList[CompCount - 1];
			CompList[CompCount - 1] = p;
			CompList[CompCount - 1] = NULL;
			Gate* gate = dynamic_cast<Gate*>(p);
			switch_key* key = dynamic_cast<switch_key*>(p);
			LED* led = dynamic_cast<LED*>(p);
			if (gate != NULL)
			{
				OutputPin* out = gate->getoutputpin();
				int num_conn = out->get_m_Conn();
				Connection** m_Connections = out->get_m_Connections();
				for (int i = 0; i < num_conn; i++)
				{
					m_Connections[i]->set_selected(true);
				}
				num_conn = 0;

				
			}
			else if (key != NULL)
			{
				OutputPin* out = key->getoutputpin();
				int num_conn =  out->get_m_Conn();
				Connection** m_Connections = out->get_m_Connections();
				for (int i = 0; i < num_conn; i++)
				{
					m_Connections[i]->set_selected(true);
				}
				num_conn = 0;

			}
			//else if (led != NULL)
			//{
			//	//InputPin* in = led->getinputpin();


			//}
			delete p;
			i--;
			CompCount--;
		}
	}
	OutputInterface->DeleteDrawingArea();
	UpdateInterface();
}
////////////////////////////////
//load connection
Component* ApplicationManager::load_connection(int id1)
{
	Component* p;
	for (int i = 0; i < CompCount; i++)
	{
		p = CompList[i];
		if (p->get_ID() == id1)
		{
			break;
		}

	}
	return p;
}
