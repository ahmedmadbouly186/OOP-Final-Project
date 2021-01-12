#include "Cut.h"
#include "..\ApplicationManager.h"
#include  "..\Components\Gate.h"
#include "..\Components\LED.h"
#include "..\Components\switch_key.h"
#include"..\Components\AND2.h"
#include"..\Components\AND3.h"
#include"..\Components\Buff.h"
#include"..\Components\INV.h"
#include"..\Components\LED.h"
#include"..\Components\NAND2.h"
#include"..\Components\NOR2.h"
#include"..\Components\NOR3.h"
#include"..\Components\OR2.h"
#include"..\Components\switch_key.h"
#include"..\Components\XOR2.h"
#include"..\Components\XOR3.h"
#include"..\Components\XNOR2.h"
Cut::Cut(ApplicationManager* pApp) :Action(pApp)
{
}
void Cut::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

}

void Cut::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	pManager->setcut_component(NULL);
	Output* pOut = pManager->GetOutput();
	Component* x = pManager->get_selected();
	//Component* ptr_new_cutcomponent;

	if (x != NULL)
	{
		//x->setcopy(1);
		Gate* check_gate = dynamic_cast<Gate*>(x);
		LED* check_led = dynamic_cast<LED*>(x);
		switch_key* check_switch = dynamic_cast<switch_key*>(x);

		if (dynamic_cast<AND2*>(x) != NULL)
		{
			AND2* ptr_new_cutcomponent = new AND2(x->get_GraphicsInfo(), AND2_FANOUT, pManager->get_counter());
			ptr_new_cutcomponent->setlable(x->get_label());
			pManager->setcut_component(ptr_new_cutcomponent);
		}
		else if (dynamic_cast<AND3*>(x) != NULL)
		{
			AND3* ptr_new_cutcomponent = new AND3(x->get_GraphicsInfo(), AND2_FANOUT, pManager->get_counter());
			ptr_new_cutcomponent->setlable(x->get_label());
			pManager->setcut_component(ptr_new_cutcomponent);
		}
		else if (dynamic_cast<Buff*>(x) != NULL)
		{
			Buff* ptr_new_cutcomponent = new Buff(x->get_GraphicsInfo(), AND2_FANOUT, pManager->get_counter());
			ptr_new_cutcomponent->setlable(x->get_label());
			pManager->setcut_component(ptr_new_cutcomponent);
		}
		else if (dynamic_cast<INV*>(x) != NULL)
		{
			INV* ptr_new_cutcomponent = new INV(x->get_GraphicsInfo(), AND2_FANOUT, pManager->get_counter());
			ptr_new_cutcomponent->setlable(x->get_label());
			pManager->setcut_component(ptr_new_cutcomponent);
		}
		else if (dynamic_cast<NAND2*>(x) != NULL)
		{
			NAND2* ptr_new_cutcomponent = new NAND2(x->get_GraphicsInfo(), AND2_FANOUT, pManager->get_counter());
			ptr_new_cutcomponent->setlable(x->get_label());
			pManager->setcut_component(ptr_new_cutcomponent);
		}
		else if (dynamic_cast<NOR2*>(x) != NULL)
		{
			NOR2* ptr_new_cutcomponent = new NOR2(x->get_GraphicsInfo(), AND2_FANOUT, pManager->get_counter());
			ptr_new_cutcomponent->setlable(x->get_label());
			pManager->setcut_component(ptr_new_cutcomponent);
		}
		else if (dynamic_cast<NOR3*>(x) != NULL)
		{
			NOR3* ptr_new_cutcomponent = new NOR3(x->get_GraphicsInfo(), AND2_FANOUT, pManager->get_counter());
			ptr_new_cutcomponent->setlable(x->get_label());
			pManager->setcut_component(ptr_new_cutcomponent);
		}
		else if (dynamic_cast<OR2*>(x) != NULL)
		{
			OR2* ptr_new_cutcomponent = new OR2(x->get_GraphicsInfo(), AND2_FANOUT, pManager->get_counter());
			ptr_new_cutcomponent->setlable(x->get_label());
			pManager->setcut_component(ptr_new_cutcomponent);
		}
		else if (dynamic_cast<XNOR2*>(x) != NULL)
		{
			XNOR2* ptr_new_cutcomponent = new XNOR2(x->get_GraphicsInfo(), AND2_FANOUT, pManager->get_counter());
			ptr_new_cutcomponent->setlable(x->get_label());
			pManager->setcut_component(ptr_new_cutcomponent);
		}
		else if (dynamic_cast<XOR2*>(x) != NULL)
		{
			XOR2* ptr_new_cutcomponent = new XOR2(x->get_GraphicsInfo(), AND2_FANOUT, pManager->get_counter());
			ptr_new_cutcomponent->setlable(x->get_label());
			pManager->setcut_component(ptr_new_cutcomponent);
		}
		else if (dynamic_cast<XOR3*>(x) != NULL)
		{
			XOR3* ptr_new_cutcomponent = new XOR3(x->get_GraphicsInfo(), AND2_FANOUT, pManager->get_counter());
			ptr_new_cutcomponent->setlable(x->get_label());
			pManager->setcut_component(ptr_new_cutcomponent);
		}
		else if (dynamic_cast<LED*>(x) != NULL)
		{
			LED* ptr_new_cutcomponent = new LED(x->get_GraphicsInfo(), pManager->get_counter());
			ptr_new_cutcomponent->setlable(x->get_label());
			pManager->setcut_component(ptr_new_cutcomponent);
		}
		else if (dynamic_cast<switch_key*>(x) != NULL)
		{
			switch_key* ptr_new_cutcomponent = new switch_key(x->get_GraphicsInfo(), AND2_FANOUT, pManager->get_counter());
			ptr_new_cutcomponent->setlable(x->get_label());
			pManager->setcut_component(ptr_new_cutcomponent);
		}
		pOut->PrintMsg("componnent cut");
		x->set_selected(true);
		pManager->Delete();
	}
}

void Cut::Undo()
{
}

void Cut::Redo()
{
}
Cut::~Cut(void)
{
}