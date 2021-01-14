#include "EDITLABLE.h"
#include"..\Components\Gate.h"
#include "..\ApplicationManager.h"
#include"..\Components\Connection.h"
#include"../Components/LED.h"
#include"../Components/switch_key.h"
EDITLABLE::EDITLABLE(ApplicationManager* pApp) :Action(pApp)
{
	//a = pApp;
}

EDITLABLE::~EDITLABLE(void)
{
}

void EDITLABLE::ReadActionParameters()
{


}

void EDITLABLE::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	string x;
	//Component** z = pManager->get_CompList();
	Component* y;
	string press;
	int x1;
	int y1;
	int x2;
	int y2;
	GraphicsInfo m;
	pOut->PrintMsg(" to edit lable press 1  to edit source press 2  to edit destination press 3");
	press = pIn->GetSrting(pOut, 1);
	pOut->ClearStatusBar();
	if (press == "1")
	{
		//for (int i = 0; i < pManager->get_compcount(); i++)
		{
			y = pManager->get_selected();
			if (y != NULL)
			{
				//if (dynamic_cast<Gate*>(z[i])) {
				x = pIn->GetSrting(pOut);
				y->setlable(x);
				y->drawlable(pOut, x, y->get_GraphicsInfo().x2, y->get_GraphicsInfo().y2);
				pOut->ClearDrawingArea();

			}

		}
	}
	else if (press == "2")
	{
		//for (int i = 0; i < pManager->get_compcount(); i++)
		{
			//OutputPin* pSrcPin;
			Connection* p;
			p = pManager->get_connection();
			if (p != NULL)
			{
				Gate* s;
				switch_key* k;
				//for (int j = 0; j < pManager->get_compcount(); j++)
				s = pManager->get_gate();
				y = pManager->get_selected();
				k = dynamic_cast<switch_key*>(y);
				if (s != NULL)
				{
					int* num = &p->getSourcePin()->get_m_Conn();
					int num_conn = *num;
					num_conn--;
					*num = num_conn;
					p->setSourcePin(s->getoutputpin());

					m = s->get_GraphicsInfo();

					x1 = m.x2;
					y1 = m.y2 - UI.AND2_Width / 2;
					p->set_Point1(x1, y1);

					pOut->ClearDrawingArea();
					pOut->PrintMsg("edit done 2");


				}
				else if (k != NULL)
				{
					int* num = &p->getSourcePin()->get_m_Conn();
					int num_conn = *num;
					num_conn--;
					*num = num_conn;
					p->setSourcePin(k->getoutputpin());

					m = k->get_GraphicsInfo();

					x1 = m.x2;
					y1 = m.y2 - UI.AND2_Width / 2;
					p->set_Point1(x1, y1);

					pOut->ClearDrawingArea();
					pOut->PrintMsg("edit done 2");

				}

			}


		}
	}
	else if (press == "3")
	{
		//for (int i = 0; i < pManager->get_compcount(); i++)
		{
			//OutputPin* surcPin;
			Connection* p;
			//if (z[i]->get_selected() == true)
			{
				p = pManager->get_connection();
				if (p != NULL)
				{
					

					LED* l;
					y = pManager->get_selected();
					l = dynamic_cast<LED*>(y);
					Gate* s;
					//for (int j = 0; j < pManager->get_compcount(); j++)
					s = pManager->get_gate();
					if (s != NULL)
					{
						m = s->get_GraphicsInfo();
						if (s->no_inputs() == 1)
						{
							x2 = m.x1;
							y2 = m.y2 - UI.AND2_Width / 2;
							p->set_Point2(x2, y2);
						}
						else if (s->no_inputs() == 2)
						{
							if (p->get_PinNumber() == 1)
							{
								x2 = m.x1;
								y2 = m.y2 - 2 * UI.AND2_Width / 3;
								p->set_Point2(x2, y2);
							}
							else
							{
								x2 = m.x1;
								y2 = m.y2 - UI.AND2_Width / 3;
								p->set_Point2(x2, y2);
							}
						}
						else
						{
							if (p->get_PinNumber() == 1)
							{
								x2 = m.x1;
								y2 = m.y1 + UI.AND2_Width / 4;
								p->set_Point2(x2, y2);
							}
							else if (p->get_PinNumber() == 2)
							{
								x2 = m.x1;
								y2 = m.y1 + UI.AND2_Width / 2;
								p->set_Point2(x2, y2);
							}
							else
							{
								x2 = m.x1;
								y2 = m.y1 + 3 * UI.AND3_Width / 4;
								p->set_Point2(x2, y2);
							}
						}
					}
					else if (l != NULL)
					{
						m = l->get_GraphicsInfo();
						x2 = m.x1;
						y2 = m.y2 - UI.AND2_Width / 2;
						p->set_Point2(x2, y2);
					}
					Component* dest_comp;
					Gate* g;
					LED* L;
					dest_comp = p->getDestPin()->getComponent();
					L = dynamic_cast<LED*>(dest_comp);
					g = dynamic_cast<Gate*>(dest_comp);
					if (s != NULL)
					{
						//p->getDestPin()->getComponent()->setcset_connection(0, p->get_PinNumber()-1);
						if (g != NULL)
						{
							g->set_connection(0, p->get_PinNumber() - 1);
						}
						else if (L != NULL)
						{
							L->set_connection(0);
						}
						string ninput;
						pOut->PrintMsg("enter the number of input pin");
						ninput = pIn->GetSrting(pOut, 1);
						const char c[] = { ninput[0] };
						int n = atoi(c);
						if (n <= s->no_inputs())
						{

							p->setDestPin(s->getinputpin(n));
							m = s->get_GraphicsInfo();
							x2 = m.x1;
							y2 = m.y2 - UI.AND2_Width / 2;
							p->set_Point2(x2, y2);

							pOut->ClearDrawingArea();
							pManager->UpdateInterface();
							pOut->PrintMsg("edit done 3");
						}
					}
					else if (l != NULL)
					{
						if (g != NULL)
						{
							g->set_connection(0, p->get_PinNumber() - 1);
						}
						else if (L != NULL)
						{
							L->set_connection(0);
						}
						p->setDestPin(l->getinputpin());
						m = l->get_GraphicsInfo();
						x2 = m.x1;
						y2 = m.y2 - UI.AND2_Width / 2;
						p->set_Point2(x2, y2);

						pOut->ClearDrawingArea();
						pManager->UpdateInterface();
						pOut->PrintMsg("edit done 3");
					}
					/*string ninput;
					pOut->PrintMsg("enter the number of input pin");
					ninput = pIn->GetSrting(pOut,1);
					const char c[] = { ninput[0] };
					int n = atoi(c);
					if (n <= s->no_inputs())
					*/
					/*{
						x2 = m.x1;
						y2 = m.y2 - UI.AND2_Width / 2;
						p->set_Point2(x2, y2);

						pOut->ClearDrawingArea();
						pManager->UpdateInterface();
						pOut->PrintMsg("edit done 3");
					}*/
				}

			}
		}
	}
	else
	{
		pOut->PrintMsg("failed");
	}
}
void EDITLABLE::Undo()
{}

void EDITLABLE::Redo()
{}

