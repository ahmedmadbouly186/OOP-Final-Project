#include "load.h"
#include "../Components/AND2.h"
#include "../Components/Buff.h"
#include "../Components/Component.h"
#include "../Components/INV.h"
#include "../Components/LED.h"
#include "../Components/NAND2.h"
#include "../Components/NOR2.h"
#include "../Components/NOR3.h"
#include "../Components/switch_key.h"
#include "../Components/XNOR2.h"
#include "../Components/XOR2.h"
#include "../Components/XOR3.h"
#include "../Components/OR2.h"
#include "..\ApplicationManager.h"
#include "../Components/InputPin.h"
#include "../Components/OutputPin.h"
#include "../Components/Gate.h"
#include "../Components/Connection.h"
#include <fstream>
load::load(ApplicationManager* pApp) :Action(pApp)
{

}
void load::ReadActionParameters()
{
	////Get a Pointer to the Input / Output Interfaces
	//Output* pOut = pManager->GetOutput();
	//Input* pIn = pManager->GetInput();

	////Print Action Message
	//pOut->PrintMsg("Click on the component you want to select");

	////Wait for User Input
	//pIn->GetPointClicked(Cx, Cy);

	////Clear Status Bar
	//pOut->ClearStatusBar();

}

void load::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ifstream inputfile;
	string name;
	name = pIn->Getfilename(pOut);

	inputfile.open(name);
	if (!inputfile.is_open())
	{
		pOut->PrintMsg("There is an Error in loading, please try again");
		return;
	}
	int first_word;
	inputfile >> first_word;
	if (first_word != -1)
	{
		int type;
		char label[30];
		int x;
		int y;
		int id;
		int Len = UI.XOR2_Width;
		int Wdth = UI.XOR2_Height;
		GraphicsInfo GInfo;
		//Component* comp;
		int numcomp = first_word;
		for (int i = 0; i < numcomp; i++)
		{
			inputfile >> type;
			switch (type)
			{
			case And2:
				inputfile >> id >> label >> x >> y;
				GInfo.x1 = x;
				GInfo.x2 = x + Len;
				GInfo.y1 = y;
				GInfo.y2 = y + Wdth;
				AND2*and;
				and = new AND2(GInfo, AND2_FANOUT, id);
				and ->set_label(label);
				pManager->AddComponent(and);
				break;
			case Or2:
				inputfile >> id >> label >> x >> y;
				GInfo.x1 = x;
				GInfo.x2 = x + Len;
				GInfo.y1 = y;
				GInfo.y2 = y + Wdth;
				OR2* or;
				or = new OR2(GInfo, AND2_FANOUT, id);
				or ->set_label(label);
				pManager->AddComponent(or);
				break;
			case Buffer:
				inputfile >> id >> label >> x >> y;
				GInfo.x1 = x;
				GInfo.x2 = x + Len;
				GInfo.y1 = y;
				GInfo.y2 = y + Wdth;
				Buff* buff;
				buff = new Buff(GInfo, AND2_FANOUT, id);
				buff->set_label(label);
				pManager->AddComponent(buff);
				break;
			case Inverter:
				inputfile >> id >> label >> x >> y;
				GInfo.x1 = x;
				GInfo.x2 = x + Len;
				GInfo.y1 = y;
				GInfo.y2 = y + Wdth;
				INV* inv;
				inv = new INV(GInfo, AND2_FANOUT, id);
				inv->set_label(label);
				pManager->AddComponent(inv);
				break;
			case Led:
				inputfile >> id >> label >> x >> y;
				GInfo.x1 = x;
				GInfo.x2 = x + Len;
				GInfo.y1 = y;
				GInfo.y2 = y + Wdth;
				LED* led;
				led = new LED(GInfo, id);
				led->set_label(label);
				pManager->AddComponent(led);
				break;
			case Nand2:
				inputfile >> id >> label >> x >> y;
				GInfo.x1 = x;
				GInfo.x2 = x + Len;
				GInfo.y1 = y;
				GInfo.y2 = y + Wdth;
				NAND2* nand2;
				nand2 = new NAND2(GInfo, AND2_FANOUT, id);
				nand2->set_label(label);
				pManager->AddComponent(nand2);
				break;
			case Nor2:
				inputfile >> id >> label >> x >> y;
				GInfo.x1 = x;
				GInfo.x2 = x + Len;
				GInfo.y1 = y;
				GInfo.y2 = y + Wdth;
				NOR2* nor2;
				nor2 = new NOR2(GInfo, AND2_FANOUT, id);
				nor2->set_label(label);
				pManager->AddComponent(nor2);
				break;
			case Nor3:
				inputfile >> id >> label >> x >> y;
				GInfo.x1 = x;
				GInfo.x2 = x + Len;
				GInfo.y1 = y;
				GInfo.y2 = y + Wdth;
				NOR3* nor3;
				nor3 = new NOR3(GInfo, AND2_FANOUT, id);
				nor3->set_label(label);
				pManager->AddComponent(nor3);
				break;
			case Switch:
				inputfile >> id >> label >> x >> y;
				GInfo.x1 = x;
				GInfo.x2 = x + Len;
				GInfo.y1 = y;
				GInfo.y2 = y + Wdth;
				switch_key* switch_k;
				switch_k = new switch_key(GInfo, AND2_FANOUT, id);
				switch_k->set_label(label);
				pManager->AddComponent(switch_k);
				break;
			case Xnor2:
				inputfile >> id >> label >> x >> y;
				GInfo.x1 = x;
				GInfo.x2 = x + Len;
				GInfo.y1 = y;
				GInfo.y2 = y + Wdth;
				XNOR2* xnor2;
				xnor2 = new XNOR2(GInfo, AND2_FANOUT, id);
				xnor2->set_label(label);
				pManager->AddComponent(xnor2);
				break;
			case Xor2:
				inputfile >> id >> label >> x >> y;
				GInfo.x1 = x;
				GInfo.x2 = x + Len;
				GInfo.y1 = y;
				GInfo.y2 = y + Wdth;
				XOR2* xor2;
				xor2 = new XOR2(GInfo, AND2_FANOUT, id);
				xor2->set_label(label);
				pManager->AddComponent(xor2);
				break;
			case Xor3:
				inputfile >> id >> label >> x >> y;
				GInfo.x1 = x;
				GInfo.x2 = x + Len;
				GInfo.y1 = y;
				GInfo.y2 = y + Wdth;
				XOR3* xor3;
				xor3 = new XOR3(GInfo, AND2_FANOUT, id);
				xor3->set_label(label);
				pManager->AddComponent(xor3);
				break;
				/*case And3:
				inputfile >> id >> label >> x >> y;
					GInfo.x1 = x;
				GInfo.x2 = x + Len;
				GInfo.y1 = y;
				GInfo.y2 = y + Wdth;
					AND3* and3;
					and3 = new AND3(GInfo, AND2_FANOUT, id);
					and3 ->set_label(label);
				and3 ->set_id(id);
					pManager->AddComponent(pa);
					break;
				case Or2:
				inputfile >> id >> label >> x >> y;
					GInfo.x1 = x;
				GInfo.x2 = x + Len;
				GInfo.y1 = y;
				GInfo.y2 = y + Wdth;
					OR2* or2;
					or2 = new OR2(GInfo, AND2_FANOUT, id);
					or2 ->set_label(label);
				or2 ->set_id(id);
					pManager->AddComponent(pa);
					break;*/
			}
		}
	}
	inputfile >> first_word;
	if (first_word != -1 && first_word == connection)
	{
		int id1;
		int id2;
		int num_inputpin;
		inputfile >> id1 >> id2 >> num_inputpin;
		while (id1 != -1)
		{
			GraphicsInfo GInfo1;
			GraphicsInfo GInfo2;
			GraphicsInfo GInfo3;
			OutputPin* out_pin;
			InputPin* in_pin;
			Component* comp1 = pManager->load_connection(id1);
			Component* comp2 = pManager->load_connection(id2);
			Gate* gate1 = dynamic_cast<Gate*>(comp1);
			Gate* gate2 = dynamic_cast<Gate*>(comp2);
			switch_key* key = dynamic_cast<switch_key*>(comp1);
			LED* led = dynamic_cast<LED*>(comp2);
			GInfo1 = comp1->get_GraphicsInfo();
			GInfo2 = comp2->get_GraphicsInfo();
			if (gate1 != NULL)
			{
				out_pin = gate1->getoutputpin();
			}
			else if (key != NULL)
			{
				out_pin = key->getoutputpin();
			}
			if (gate2 != NULL)
			{
				in_pin = gate2->getinputpin(num_inputpin);
				int num_pins = gate2->no_inputs();
				if (num_pins == 1)
				{
					GInfo3.y2 = GInfo2.y1 + (UI.AND2_Width / 2);
				}
				else if (num_pins == 2)
				{
					if (num_inputpin == 1)
					{
						GInfo3.y2 = GInfo2.y1 + (UI.AND2_Width / 3);
					}
					else
					{
						GInfo3.y2 = GInfo2.y1 + (2 * UI.AND2_Width / 3);
					}
				}
				else
				{
					if (num_inputpin == 1)
					{
						GInfo3.y2 = GInfo2.y1 + (UI.AND2_Width / 4);
					}
					else if (num_inputpin == 2)
					{
						GInfo3.y2 = GInfo2.y1 + (UI.AND2_Width / 2);
					}
					else
					{
						GInfo3.y2 = GInfo2.y1 + (3 * UI.AND2_Width / 4);
					}
				}
			}
			else if (led != NULL)
			{
				in_pin = led->getinputpin();
				GInfo3.y2 = GInfo2.y1 + (UI.AND2_Width / 2);
			}
			GInfo3.x1 = GInfo1.x2;
			GInfo3.x2 = GInfo2.x1;
			GInfo3.y1 = GInfo1.y2 - UI.AND2_Width / 2;
			Connection* connection;
			connection = new Connection(GInfo3, out_pin, in_pin, id1, id2, num_inputpin);
			pManager->AddComponent(connection);
			inputfile >> id1 >> id2 >> num_inputpin;
		}
	}
	inputfile.close();
}

void load::Undo()
{
}

void load::Redo()
{
}
load::~load(void)
{
}
