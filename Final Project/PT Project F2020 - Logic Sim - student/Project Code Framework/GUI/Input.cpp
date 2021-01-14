//#include "Input.h"
#include "Output.h"
static bool b = true;
Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}


string Input::GetSrting(Output* pOut, bool s)
{
	if (s)
	{

	}
	else
	{
		pOut->ClearStatusBar();
		char d[] = "Enter the name of label: ";
		pOut->PrintMsg(d);
	}
	char c[20];
	pWind->FlushKeyQueue();
	for (int i = 0; i < 19; i++)
	{
		pWind->WaitKeyPress(c[i]);
		c[i + 1] = '\0';
		if (c[i] == 27)
		{
			c[0] = '\0';
			break;
		}
		else if (c[i] == 13)
		{
			c[i] = '\0';
			break;
			//i = 19;
		}
		else if (c[i] == 8)
		{
			if (i > 0)
			{
				i--;
				c[i] = '\0';
				i--;
			}
		}
		pOut->PrintMsg(c);
	}
	pOut->ClearStatusBar();
	/*int MsgX = x;
	int MsgY = y;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, MsgY, c);*/
	return c;
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar

}
string Input::Getfilename(Output* pOut)
{
	char c[100];
	pOut->ClearStatusBar();
	char d[] = "Enter the name of file: ";
	pOut->PrintMsg(d);
	for (int i = 0; i < 99; i++)
	{
		pWind->WaitKeyPress(c[i]);
		c[i + 1] = '\0';
		if (c[i] == 27)
		{
			c[0] = '\0';
			break;
		}
		else if (c[i] == 13)
		{
			c[i] = '\0';
			break;
			//i = 19;
		}
		else if (c[i] == 8)
		{
			if (i > 0)
			{
				i--;
				c[i] = '\0';
				i--;
			}
		}
		pOut->PrintMsg(c);
	}
	pOut->ClearStatusBar();
	//int x, y;
	//pWind->WaitMouseClick(x, y);
	//int MsgX = x;
	//int MsgY = y;

	//// Print the Message
	//pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	//pWind->SetPen(UI.MsgColor);
	//pWind->DrawString(MsgX, MsgY, c);
	return c;
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar

}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click
	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight && b)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{

			case ITM_ADD: b = false; return ADD_Gate;
			case ITM_Simulate: return SIM_MODE;
			case ITM_LOAD: return LOAD;
			case ITM_SAVE: return SAVE;

			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_MOVE: return MOVE;
			case ITM_EDITLABLE: return EDIT_Label;

			case ITM_Delet: return DEL;
			case ITM_Connection: return ADD_CONNECTION;
			case ITM_EXIT: return EXIT;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.ToolItemWidth) + 12;


			switch (ClickedItemOrder)
			{
			case ITM_Buff: return ADD_Buff;
			case ITM_INV: return ADD_INV;
			case ITM_AND2: return ADD_AND_GATE_2;
			case ITM_OR2: return ADD_OR_GATE_2;
			case ITM_NAND2: return ADD_NAND_GATE_2;
			case ITM_NOR2: return ADD_NOR_GATE_2;
			case ITM_XOR2: return ADD_XOR_GATE_2;
			case ITM_XNOR2: return ADD_XNOR_GATE_2;
			case ITM_AND3: return ADD_AND_GATE_3;
			case ITM_NOR3: return ADD_NOR_GATE_3;
			case ITM_XOR3: return ADD_XOR_GATE_3;
			case ITM_LED: return ADD_LED;
			case ITM_Switch: return ADD_Switch;
			case ITM_Close:  b = true; return close;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{

		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			int ClickedItemOrder = (x / UI.ToolItemWidth);
			switch (ClickedItemOrder)
			{                             // Items of Simulation tool bar
			case ITM_SIM: return SIM_MODE;
			case ITM_SWITCH_DSN: return DSN_MODE;
			case ITM_SAVE_Simulate: return SAVE;
			case ITM_LOAD_Simulate: return LOAD;;
			case ITM_Change_Switch:  return Change_Switch;
			case ITM_2EXIT: return EXIT;

			default: return SIM_TOOL;	//A click on empty place in Simulation toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;

		//return SIM_MODE;	//This should be changed after creating the compelete simulation bar 
	}

}


Input::~Input()
{
}
