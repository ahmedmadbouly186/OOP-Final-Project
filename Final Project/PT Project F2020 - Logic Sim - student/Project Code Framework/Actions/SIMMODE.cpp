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
	//Get a Pointer to the Output Interfaces
	//pout = pManager->GetOutput();


}

void SIMMODE::Execute()
{
	// change from menubar to simbar
	ReadActionParameters();
	Output* pout;
	pout = pManager->GetOutput();
	pout->CleartoolbarArea1();
	pout->CreateSimulationToolBar();

	// the actually code that make the circut behave correctly

	//Gate** gatelist;
	//Connection** connectionlist1;
	//LED** ledlist;
	//switch_key** switchlist;
	//InputPin** inputpin_list;

	//int gate_count = 0;
	//int connect_count = 0;
	//int led_count = 0;
	//int switch_count = 0;
	//int inpins_count = 0;
	//int counter = 0;
	//for (int i = 0; i < 200; i++)
	//{
	//	Component* c1 = pManager->componentreturin(i);
	//	if (c1 != NULL)
	//	{
	//		Gate* g1 = dynamic_cast<Gate*>(c1);
	//		Connection* co = dynamic_cast<Connection*>(c1);
	//		LED* l = dynamic_cast<LED*>(c1);
	//		switch_key* sk = dynamic_cast<switch_key*>(c1);

	//		if (g1 != NULL)
	//		{
	//			gate_count++;
	//		}
	//		else if (co != NULL)
	//		{
	//			connect_count++;
	//		}
	//		else if (l != NULL)
	//		{
	//			led_count++;
	//		}
	//		else if (sk != NULL)
	//		{
	//			switch_count++;
	//		}

	//	}
	//	else
	//	{
	//		break;
	//	}
	//}
	//gatelist = new Gate * [gate_count];
	//connectionlist1 = new Connection * [connect_count];
	//ledlist = new LED * [led_count];
	//switchlist = new switch_key * [switch_count];
	//{
	//	int cont1 = 0;		int cont2 = 0; 		int cont3 = 0;		int cont4 = 0;
	//	for (int i = 0; i < (gate_count + connect_count + led_count + switch_count); i++)
	//	{
	//		Component* c1 = pManager->componentreturin(i);
	//		if (c1 != NULL)
	//		{
	//			Gate* g1 = dynamic_cast<Gate*>(c1);
	//			Connection* co = dynamic_cast<Connection*>(c1);
	//			LED* l = dynamic_cast<LED*>(c1);
	//			switch_key* sk = dynamic_cast<switch_key*>(c1);

	//			if (g1 != NULL)
	//			{
	//				gatelist[cont1] = g1;
	//				cont1++;
	//			}
	//			else if (co != NULL)
	//			{
	//				connectionlist1[cont2] = co;
	//				cont2++;
	//			}
	//			else if (l != NULL)
	//			{
	//				ledlist[cont3] = l;
	//				cont3++;
	//			}
	//			else if (sk != NULL)
	//			{
	//				switchlist[cont4] = sk;
	//				cont4++;
	//			}
	//		}
	//	}
	//}

	//for (int i = 0; i < gate_count; i++)
	//{
	//	int c = gatelist[i]->no_inputs();
	//	inpins_count += c;
	//}
	//inputpin_list = new InputPin * [inpins_count];
	//for (int i = 0; i < inpins_count; i++)
	//{
	//	inputpin_list[i] = NULL;
	//}
	//// first step in the simulate is chek if any inputpin in the led  is connected or not
	//	//if isnot connected --> set its status to LOW
	//	// if connected --> donot do any thing and let the simulate algorithm carry on
	//	//we repet this step also for gates but for every pin in the gate
	//for (int i = 0; i < led_count; i++)
	//{
	//	//LED *l = ledlist[i];
	//	//bool b=ledlist[i]->Isconnectto();
	//	if (ledlist[i]->Isconnectto() == false)
	//	{
	//		ledlist[i]->setInputPinStatus(1, LOW);
	//	}
	//	//l = ledlist[i];
	//}
	//for (int i = 0; i < gate_count; i++)
	//{
	//	int m = gatelist[i]->no_inputs();
	//	for (int j = 1; j <= m; j++)
	//	{
	//		if (gatelist[i]->Isconnectto(j) == false)
	//		{
	//			ledlist[i]->setInputPinStatus(j, LOW);
	//		}
	//	}
	//}


	//for (int i = 0; i < switch_count; i++)
	//{
	//	switchlist[i]->Operate();
	//	OutputPin* op = (switchlist[i]->getoutputpin()); // output pin for the current swicth 
	//	for (int i = 0; i < connect_count; i++)
	//	{
	//		OutputPin* op2 = connectionlist1[i]->getSourcePin();
	//		if (op == op2)
	//		{
	//			connectionlist1[i]->Operate();
	//			inputpin_list[counter] = connectionlist1[i]->getDestPin();
	//			counter++;
	//		}
	//	}
	//}

	//while (counter <= inpins_count) {
	//	for (int I1 = 0; I1 < gate_count; I1++)
	//	{
	//		int c = gatelist[I1]->no_inputs();
	//		int c1 = 0;
	//		for (int I2 = 0; I2 < c; I2++)
	//		{
	//			InputPin* ip = (gatelist[I1]->getinputpin(I2));
	//			for (int I3 = 0; I3 < counter; I3++)
	//			{
	//				if (inputpin_list[I3] == ip)
	//				{
	//					c1++;
	//				}
	//			}
	//		}
	//		if (c1 == c)
	//		{
	//			gatelist[I1]->Operate();

	//			OutputPin* op = (gatelist[I1]->getoutputpin()); // output pin for the current swicth 
	//			for (int I2 = 0; I2 < connect_count; I2++)
	//			{
	//				OutputPin* op2 = connectionlist1[I2]->getSourcePin();
	//				if (op == op2)
	//				{
	//					connectionlist1[I2]->Operate();
	//					inputpin_list[counter] = connectionlist1[I2]->getDestPin();
	//					counter++;
	//				}
	//			}
	//		}
	//	}
	//	if (counter = inpins_count)
	//	{
	//		counter++;
	//	}
	//}


	//for (int i = 0; i < led_count; i++)
	//{
	//	ledlist[i]->Operate();
	//}

}

void SIMMODE::Undo()
{}

void SIMMODE::Redo()
{}

