#include "Save.h"
#include "..\ApplicationManager.h"
#include "..\Components\Gate.h"
#include "..\Components\AND2.h"
#include "..\Components\Buff.h"
#include "..\Components\INV.h"
#include "..\Components\NAND2.h"
#include "..\Components\NOR2.h"
#include "..\Components\NOR3.h"
#include "..\Components\switch_key.h"
#include "..\Components\XNOR2.h"
#include "..\Components\XOR2.h"
#include "..\Components\XOR3.h"
#include "..\Components\Connection.h"
#include "..\Components\LED.h"
#include <fstream>

Save::Save(ApplicationManager* pApp) :Action(pApp)
{
}

Save::~Save(void)
{
}

void Save::ReadActionParameters()
{
}

void Save::Execute()
{	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	ofstream outputfile;
	string name;
	pOut->PrintMsg("Enter the name of file : ");
	name = pIn->Getfilename(pOut);
	outputfile.open(name);
	pManager->save(outputfile);
	outputfile.close();
	pManager->GetOutput()->PrintMsg("Circuit is saved : " + name);
	/*
	int ID = 1;

	ComponentType type;
	for (int i = 0; i < n; i++)
	{
		Component* component = dynamic_cast<AND2*>(list[i]);
		if (component != NULL)
		{
			GraphicsInfo m_grfInfo=component->get_GraphicsInfo();
			string label =component->get_label();
			type = And2;
			outputfile << And2 << "\t" << ID++ << "\t" << label << "\t" << m_grfInfo.x1 << "\t" << m_grfInfo.y1 << endl;

		}
		component = dynamic_cast<XNOR2*>(list[i]);
		if (component != NULL)
		{
			GraphicsInfo m_grfInfo = component->get_GraphicsInfo();
			string label = component->get_label();
			type = Xnor2;
			outputfile << Xnor2 << "\t" << ID++ << "\t" << label << "\t" << m_grfInfo.x1 << "\t" << m_grfInfo.y1 << endl;
		}
		component = dynamic_cast<NOR2*>(list[i]);
		if (component != NULL)
		{
			GraphicsInfo m_grfInfo = component->get_GraphicsInfo();
			string label = component->get_label();
			type = Nor2;
			outputfile << Nor2 << "\t" << ID++ << "\t" << label << "\t" << m_grfInfo.x1 << "\t" << m_grfInfo.y1 << endl;
		}
		component = dynamic_cast<NOR3*>(list[i]);
		if (component != NULL)
		{
			GraphicsInfo m_grfInfo = component->get_GraphicsInfo();
			string label = component->get_label();
			type = Nor3;
			outputfile << Nor3 << "\t" << ID++ << "\t" << label << "\t" << m_grfInfo.x1 << "\t" << m_grfInfo.y1 << endl;
		}
		component = dynamic_cast<Buff*>(list[i]);
		if (component != NULL)
		{
			GraphicsInfo m_grfInfo = component->get_GraphicsInfo();
			string label = component->get_label();
			type = Buffer;
			outputfile << Buffer << "\t" << ID++ << "\t" << label << "\t" << m_grfInfo.x1 << "\t" << m_grfInfo.y1 << endl;
		}
		component = dynamic_cast<switch_key*>(list[i]);
		if (component != NULL)
		{
			GraphicsInfo m_grfInfo = component->get_GraphicsInfo();
			string label = component->get_label();
			type = Switch;
			outputfile << Switch << "\t" << ID++ << "\t" << label << "\t" << m_grfInfo.x1 << "\t" << m_grfInfo.y1 << endl;
		}
		component = dynamic_cast<XOR2*>(list[i]);
		if (component != NULL)
		{
			GraphicsInfo m_grfInfo = component->get_GraphicsInfo();
			string label = component->get_label();
			type = Xor2;
			outputfile << Xor2 << "\t" << ID++ << "\t" << label << "\t" << m_grfInfo.x1 << "\t" << m_grfInfo.y1 << endl;
		}
		component = dynamic_cast<XOR3*>(list[i]);
		if (component != NULL)
		{
			GraphicsInfo m_grfInfo = component->get_GraphicsInfo();
			string label = component->get_label();
			type = Xor3;
			outputfile << Xor3 << "\t" << ID++ << "\t" << label << "\t" << m_grfInfo.x1 << "\t" << m_grfInfo.y1 << endl;
		}
		component = dynamic_cast<LED*>(list[i]);
		if (component != NULL)
		{
			GraphicsInfo m_grfInfo = component->get_GraphicsInfo();
			string label = component->get_label();
			type = Led;
			outputfile << Led << "\t" << ID++ << "\t" << label << "\t" << m_grfInfo.x1 << "\t" << m_grfInfo.y1 << endl;
		}
		component = dynamic_cast<NAND2*>(list[i]);
		if (component != NULL)
		{
			GraphicsInfo m_grfInfo = component->get_GraphicsInfo();
			string label = component->get_label();
			type = Nand2;
			outputfile << Nand2 << "\t" << ID++ << "\t" << label << "\t" << m_grfInfo.x1 << "\t" << m_grfInfo.y1 << endl;
		}
		component = dynamic_cast<INV*>(list[i]);
		if (component != NULL)
		{
			GraphicsInfo m_grfInfo = component->get_GraphicsInfo();
			string label = component->get_label();
			type = Inverter;
			outputfile << Inverter << "\t" << ID++ << "\t" << label << "\t" << m_grfInfo.x1 << "\t" << m_grfInfo.y1 << endl;
		}
	}
	Connection* p;
	*/
}

void Save::Undo()
{}

void Save::Redo()
{}