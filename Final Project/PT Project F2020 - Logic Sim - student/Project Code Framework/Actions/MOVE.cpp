#include "MOVE.h"
#include "..\ApplicationManager.h"
#include "..\Components\Connection.h"
//#include"Components/Gate.h"
#include "../Components/Gate.h"


Move::Move(ApplicationManager* pApp) :Action(pApp)
{

}
void Move::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Wait for User Input
	pOut->PrintMsg("Click on Component you want to move");

	pIn->GetPointClicked(Cx1, Cy1);

	pOut->PrintMsg("Click on place you want to move to");

	pIn->GetPointClicked(Cx2, Cy2);
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Move::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	//int count = pManager->get_compcount();
	Component* component = pManager->ComponentRegion(Cx1,Cy1);
	if (component != NULL)
	{
		GraphicsInfo x_info;
		x_info.x1 = Cx2 - UI.AND2_Width/2;
		x_info.x2 = Cx2 + UI.AND2_Width/2;
		x_info.y1 = Cy2 - UI.AND2_Width/2;
		x_info.y2= Cy2 + UI.AND2_Width/2;
		GraphicsInfo y_info=component->get_GraphicsInfo();
		int x1 = (y_info.x1 - x_info.x1);
		int y1 = (y_info.y1 - x_info.y1);
		int x2 = (y_info.x2 - x_info.x2);
		int y2 = (y_info.y2 - x_info.y2);
		component->set_GraphicsInfo(x_info);
		
		int n = 0;
		for (int i = 0; i < 4; i++)
		{
			Connection* connection = pManager->get_connections(component->get_ID(), n);
			if (connection != NULL)
			{
				if (component->get_ID() == connection->get_ID1())
				{
					x1 = x_info.x2;
					y1 = x_info.y2 - UI.AND2_Width / 2;
					connection->set_Point1(x1, y1);
				}
				else
				{
					Gate* gate = dynamic_cast<Gate*>(component);
					if (gate != NULL)
					{
						int number_of_inputs = gate->no_inputs();
						int m = connection->get_PinNumber();
						if (number_of_inputs == 1)
						{
							x2 = x_info.x1;
							y2 = x_info.y2 - UI.AND2_Width / 2;
							connection->set_Point2(x2, y2);
						}
						else if (number_of_inputs==2)
						{
							if (m == 1)
							{
								x2 = x_info.x1;
								y2 = x_info.y2 - 2*UI.AND2_Width / 3;
								connection->set_Point2(x2, y2);
							}
							else
							{
								x2 = x_info.x1;
								y2 = x_info.y2 - UI.AND2_Width / 3;
								connection->set_Point2(x2, y2);
							}
						}
						else
						{
							if (m == 1)
							{
								x2 = x_info.x1;
								y2 = x_info.y1 +  UI.AND2_Width / 4;
								connection->set_Point2(x2, y2);
							}
							else if(m==2)
							{
								x2 = x_info.x1;
								y2 = x_info.y1 + UI.AND2_Width / 2;
								connection->set_Point2(x2, y2);
							}
							else
							{
								x2 = x_info.x1;
								y2 = x_info.y1 + 3*UI.AND3_Width / 4;
								connection->set_Point2(x2, y2);
							}
						}
					}
					else
					{
						x2 = x_info.x1;
						y2 = x_info.y2 - UI.AND2_Width / 3;
						connection->set_Point2(x2, y2);			
					}
				}
			}
		}
		pOut->ClearDrawingArea();
	
	}
	/*
	for (int i = 0; i < count; i++)
	{
		Component* y = x[i];
		GraphicsInfo t = y->get_GraphicsInfo();
		if (y->get_selected() == true)
		{
			GraphicsInfo m;
			m.x1 = Cx - UI.AND2_Width;
			m.y1 = Cy - UI.AND2_Width;
			m.x2 = Cx + UI.AND2_Width;
			m.y2 = Cx + UI.AND2_Width;
			y->set_GraphicsInfo(m);
			break;
		}
	}*/
}

void Move::Undo()
{
}

void Move::Redo()
{
}
Move::~Move(void)
{
}