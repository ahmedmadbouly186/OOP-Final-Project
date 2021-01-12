#include "Paste.h"
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
#include "..\ApplicationManager.h"

Paste::Paste(ApplicationManager* pApp) :Action(pApp)
{

}
void Paste::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message

	//Wait for User Input
	pOut->PrintMsg("Click on place you want to paste component to");

	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Paste::Execute()
{

	//Get Center point of the Gate
	ReadActionParameters();


	Component* comp = pManager->getcut_component();
	if (comp != NULL)
	{
		GraphicsInfo GInfo;
		int Len = UI.XOR3_Width;
		int Wdth = UI.XOR3_Height;
		GInfo.x1 = Cx - Len / 2;
		GInfo.x2 = Cx + Len / 2;
		GInfo.y1 = Cy - Wdth / 2;
		GInfo.y2 = Cy + Wdth / 2;
		comp->set_GraphicsInfo(GInfo);
		pManager->AddComponent(comp);
		pManager->setcut_component(NULL);
	}

	else
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		//int count = pManager->get_compcount();
		//Component** x = pManager->get_CompList();
		//for (int i = 0; i < count; i++)
		string z;
		bool finish = true;
		Component* y = pManager->get_selected();

		if (y != NULL)
		{
			//while (finish) {
				//GraphicsInfo t = y->get_GraphicsInfo();
				if (y->getcopy() == true)
				{
					int Len = UI.XOR3_Width;
					int Wdth = UI.XOR3_Height;

					GraphicsInfo GInfo;

					GInfo.x1 = Cx - Len / 2;
					GInfo.x2 = Cx + Len / 2;
					GInfo.y1 = Cy - Wdth / 2;
					GInfo.y2 = Cy + Wdth / 2;
					if (GInfo.y1 > UI.ToolBarHeight && GInfo.y2 < UI.height - UI.StatusBarHeight && GInfo.x1 > 0 && GInfo.x2 < UI.width)
					{
						Component* pA;
						if (pA = dynamic_cast<AND2*>(y)) {
							pA = new AND2(GInfo, AND2_FANOUT, pManager->get_counter());
							pManager->AddComponent(pA);
							pA->Draw(pOut);
							pA->setlable(y->get_label());
							pA->drawlable(pOut, y->get_label(), pA->get_GraphicsInfo().x2, pA->get_GraphicsInfo().y2);
							pOut->PrintMsg("if you dont want to  paste this component again enter 1,else enter anything");
							z = pIn->GetSrting(pOut, true);
							if (z == "1")
							{
								finish = false;
								y->setcopy(0);
							}
						}
						else if (pA = dynamic_cast<AND3*>(y))
						{
							pA = new AND3(GInfo, AND2_FANOUT, pManager->get_counter());
							pManager->AddComponent(pA);
							pA->Draw(pOut);
							pA->setlable(y->get_label());
							pA->drawlable(pOut, y->get_label(), pA->get_GraphicsInfo().x2, pA->get_GraphicsInfo().y2);
							pOut->PrintMsg("if you dont want to  paste this component again enter 1,else enter anything");
							z = pIn->GetSrting(pOut, true);
							if (z == "1")
							{
								finish = false;
								y->setcopy(0);
							}
						}
						else if (pA = dynamic_cast<Buff*>(y))
						{
							pA = new Buff(GInfo, AND2_FANOUT, pManager->get_counter());
							pManager->AddComponent(pA);
							pA->Draw(pOut);
							pA->setlable(y->get_label());
							pA->drawlable(pOut, y->get_label(), pA->get_GraphicsInfo().x2, pA->get_GraphicsInfo().y2);
							pOut->PrintMsg("if you dont want to  paste this component again enter 1,else enter anything");
							z = pIn->GetSrting(pOut, true);
							if (z == "1")
							{
								finish = false;
								y->setcopy(0);
							}
						}
						else if (pA = dynamic_cast<INV*>(y))
						{
							pA = new INV(GInfo, AND2_FANOUT, pManager->get_counter());
							pManager->AddComponent(pA);
							pA->Draw(pOut);
							pA->setlable(y->get_label());
							pA->drawlable(pOut, y->get_label(), pA->get_GraphicsInfo().x2, pA->get_GraphicsInfo().y2);
							pOut->PrintMsg("if you dont want to  paste this component again enter 1,else enter anything");
							z = pIn->GetSrting(pOut, true);
							if (z == "1")
							{
								finish = false;
								y->setcopy(0);
							}
						}
						else if (pA = dynamic_cast<LED*>(y))
						{
							pA = new LED(GInfo, pManager->get_counter());
							pManager->AddComponent(pA);
							pA->Draw(pOut);
							pA->setlable(y->get_label());
							pA->drawlable(pOut, y->get_label(), pA->get_GraphicsInfo().x2, pA->get_GraphicsInfo().y2);
							pOut->PrintMsg("if you dont want to  paste this component again enter 1,else enter anything");
							z = pIn->GetSrting(pOut, true);
							if (z == "1")
							{
								finish = false;
								y->setcopy(0);
							}
						}
						else if (pA = dynamic_cast<NAND2*>(y))
						{
							pA = new NAND2(GInfo, AND2_FANOUT, pManager->get_counter());
							pManager->AddComponent(pA);
							pA->Draw(pOut);
							pA->setlable(y->get_label());
							pA->drawlable(pOut, y->get_label(), pA->get_GraphicsInfo().x2, pA->get_GraphicsInfo().y2);
							pOut->PrintMsg("if you dont want to  paste this component again enter 1,else enter anything");
							z = pIn->GetSrting(pOut, true);
							if (z == "1")
							{
								finish = false;
								y->setcopy(0);
							}
						}
						else if (pA = dynamic_cast<NOR2*>(y))
						{
							pA = new NOR2(GInfo, AND2_FANOUT, pManager->get_counter());
							pManager->AddComponent(pA);
							pA->Draw(pOut);
							pA->setlable(y->get_label());
							pA->drawlable(pOut, y->get_label(), pA->get_GraphicsInfo().x2, pA->get_GraphicsInfo().y2);
							pOut->PrintMsg("if you dont want to  paste this component again enter 1,else enter anything");
							z = pIn->GetSrting(pOut, true);
							if (z == "1")
							{
								finish = false;
								y->setcopy(0);
							}
						}
						else if (pA = dynamic_cast<NOR3*>(y))
						{
							pA = new NOR3(GInfo, AND2_FANOUT, pManager->get_counter());
							pManager->AddComponent(pA);
							pA->Draw(pOut);
							pA->setlable(y->get_label());
							pA->drawlable(pOut, y->get_label(), pA->get_GraphicsInfo().x2, pA->get_GraphicsInfo().y2);
							pOut->PrintMsg("if you dont want to  paste this component again enter 1,else enter anything");
							z = pIn->GetSrting(pOut, true);
							if (z == "1")
							{
								finish = false;
								y->setcopy(0);
							}
						}
						else if (pA = dynamic_cast<OR2*>(y))
						{
							pA = new OR2(GInfo, AND2_FANOUT, pManager->get_counter());
							pManager->AddComponent(pA);
							pA->Draw(pOut);
							pA->setlable(y->get_label());
							pA->drawlable(pOut, y->get_label(), pA->get_GraphicsInfo().x2, pA->get_GraphicsInfo().y2);
							pOut->PrintMsg("if you dont want to  paste this component again enter 1,else enter anything");
							z = pIn->GetSrting(pOut, true);
							if (z == "1")
							{
								finish = false;
								y->setcopy(0);
							}
						}
						else if (pA = dynamic_cast<switch_key*>(y))
						{
							pA = new switch_key(GInfo, AND2_FANOUT, pManager->get_counter());
							pManager->AddComponent(pA);
							pA->Draw(pOut);
							pA->setlable(y->get_label());
							pA->drawlable(pOut, y->get_label(), pA->get_GraphicsInfo().x2, pA->get_GraphicsInfo().y2);
							pOut->PrintMsg("if you dont want to  paste this component again enter 1,else enter anything");
							z = pIn->GetSrting(pOut, true);
							if (z == "1")
							{
								finish = false;
								y->setcopy(0);
							}
						}
						else if (pA = dynamic_cast<XOR2*>(y))
						{
							pA = new XOR2(GInfo, AND2_FANOUT, pManager->get_counter());
							pManager->AddComponent(pA);
							pA->Draw(pOut);
							pA->setlable(y->get_label());
							pA->drawlable(pOut, y->get_label(), pA->get_GraphicsInfo().x2, pA->get_GraphicsInfo().y2);
							pOut->PrintMsg("if you dont want to  paste this component again enter 1,else enter anything");
							z = pIn->GetSrting(pOut, true);
							if (z == "1")
							{
								finish = false;
								y->setcopy(0);
							}
						}
						else if (pA = dynamic_cast<XOR3*>(y))
						{
							pA = new XOR3(GInfo, AND2_FANOUT, pManager->get_counter());
							pManager->AddComponent(pA);
							pA->Draw(pOut);
							pA->setlable(y->get_label());
							pA->drawlable(pOut, y->get_label(), pA->get_GraphicsInfo().x2, pA->get_GraphicsInfo().y2);
							pOut->PrintMsg("if you dont want to  paste this component again enter 1,else enter anything");
							z = pIn->GetSrting(pOut, true);
							if (z == "1")
							{
								finish = false;
								y->setcopy(0);
							}
						}
						else if (pA = dynamic_cast<XNOR2*>(y))
						{
							pA = new XNOR2(GInfo, AND2_FANOUT, pManager->get_counter());
							pManager->AddComponent(pA);
							pA->Draw(pOut);
							pA->setlable(y->get_label());
							pA->drawlable(pOut, y->get_label(), pA->get_GraphicsInfo().x2, pA->get_GraphicsInfo().y2); pOut->PrintMsg("if you dont want to  paste this component again enter 1,else enter anything");
							z = pIn->GetSrting(pOut, true);
							if (z == "1")
							{
								finish = false;
								y->setcopy(0);
							}
						}
					}
				}
			}
		}
	}
//}

void Paste::Undo()
{
}

void Paste::Redo()
{
}
Paste::~Paste(void)
{
}