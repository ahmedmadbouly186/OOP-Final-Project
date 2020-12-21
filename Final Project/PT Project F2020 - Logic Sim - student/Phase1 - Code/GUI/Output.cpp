#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLUE;
	UI.BkGrndColor = WHITE;

	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Programming Techniques Project");

	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar


}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	//Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
//Clears the drawing (degin) area

void Output::ClearDrawingArea() const
{
	pWind->SetPen(RED, 1);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(UI.ToolItemWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}

// clears the Tool bar area
void Output::CleartoolbarArea1()const
{
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//You can draw the tool bar icons in any way you want.

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_ADD] = "images\\Menu\\Menu_ADD.jpg"; //1 index 0
	MenuItemImages[ITM_Simulate] = "images\\Menu\\Menu_Simulate.jpg"; //2 index 1
	MenuItemImages[ITM_LOAD] = "images\\Menu\\Menu_LOAD.jpg";//3 index 2
	MenuItemImages[ITM_UNDO] = "images\\Menu\\Menu_UNDO.jpg";//4 index 3
	MenuItemImages[ITM_REDO] = "images\\Menu\\Menu_REDO.jpg";//5 index 4
	MenuItemImages[ITM_SAVE] = "images\\Menu\\Menu_SAVE.jpg";//6 index 5
	MenuItemImages[ITM_Delet] = "images\\Menu\\images.jpg";//7 index 6
	MenuItemImages[ITM_Connection] = "images\\Menu\\Menu_Connection.jpg";//8 index 7
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";//9 index 8


	MenuItemImages[ITM_Buff] = "images\\Menu\\Menu_Buff.jpg";//10 index 9
	MenuItemImages[ITM_INV] = "images\\Menu\\Menu_INV.jpg";//11 index 10
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";//12 index 11
	MenuItemImages[ITM_OR2] = "images\\Menu\\Menu_OR2.jpg";//13 index 12
	MenuItemImages[ITM_NAND2] = "images\\Menu\\Menu_NAND2.jpg";//14 index 13
	MenuItemImages[ITM_NOR2] = "images\\Menu\\Menu_NOR2.jpg";//15 index 14
	MenuItemImages[ITM_XOR2] = "images\\Menu\\Menu_XOR2.jpg";//16 index 15
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\Menu_XNOR2.jpg";//17 index 16
	MenuItemImages[ITM_AND3] = "images\\Menu\\Menu_AND3.jpg";//18 index 17
	MenuItemImages[ITM_NOR3] = "images\\Menu\\Menu_NOR3.jpg";//19 index 18
	MenuItemImages[ITM_XOR3] = "images\\Menu\\Menu_XOR3.jpg";//20 index 19
	MenuItemImages[ITM_LED] = "images\\Menu\\Menu_LED.jpg";//21 index 20
	MenuItemImages[ITM_Switch] = "images\\Menu\\Menu_Switch.jpg";//22 index 21
	MenuItemImages[ITM_Close] = "images\\Menu\\Menu_Close.jpg";//23 index 22

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time

	for (int i = 0; i < 9; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	}

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}



void Output::CreateDesignToolBar2() const
{

	UI.AppMode = DESIGN;
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_ADD] = "images\\Menu\\Menu_ADD.jpg"; //1 index 0
	MenuItemImages[ITM_Simulate] = "images\\Menu\\Menu_Simulate.jpg"; //2 index 1
	MenuItemImages[ITM_LOAD] = "images\\Menu\\Menu_LOAD.jpg";//3 index 2
	MenuItemImages[ITM_UNDO] = "images\\Menu\\Menu_UNDO.jpg";//4 index 3
	MenuItemImages[ITM_REDO] = "images\\Menu\\Menu_REDO.jpg";//5 index 4
	MenuItemImages[ITM_SAVE] = "images\\Menu\\Menu_SAVE.jpg";//6 index 5
	MenuItemImages[ITM_Delet] = "images\\Menu\\images.jpg";//7 index 6
	MenuItemImages[ITM_Connection] = "images\\Menu\\Menu_Connection.jpg";//8 index 7
	MenuItemImages[ITM_EXIT] = "images\\Menu\\Menu_Exit.jpg";//9 index 8


	MenuItemImages[ITM_Buff] = "images\\Menu\\Menu_Buff.jpg";//10 index 9
	MenuItemImages[ITM_INV] = "images\\Menu\\Menu_INV.jpg";//11 index 10
	MenuItemImages[ITM_AND2] = "images\\Menu\\Menu_AND2.jpg";//12 index 11
	MenuItemImages[ITM_OR2] = "images\\Menu\\Menu_OR2.jpg";//13 index 12
	MenuItemImages[ITM_NAND2] = "images\\Menu\\Menu_NAND2.jpg";//14 index 13
	MenuItemImages[ITM_NOR2] = "images\\Menu\\Menu_NOR2.jpg";//15 index 14
	MenuItemImages[ITM_XOR2] = "images\\Menu\\Menu_XOR2.jpg";//16 index 15
	MenuItemImages[ITM_XNOR2] = "images\\Menu\\Menu_XNOR2.jpg";//17 index 16
	MenuItemImages[ITM_AND3] = "images\\Menu\\Menu_AND3.jpg";//18 index 17
	MenuItemImages[ITM_NOR3] = "images\\Menu\\Menu_NOR3.jpg";//19 index 18
	MenuItemImages[ITM_XOR3] = "images\\Menu\\Menu_XOR3.jpg";//20 index 19
	MenuItemImages[ITM_LED] = "images\\Menu\\Menu_LED.jpg";//21 index 20
	MenuItemImages[ITM_Switch] = "images\\Menu\\Menu_Switch.jpg";//22 index 21
	MenuItemImages[ITM_Close] = "images\\Menu\\Menu_Close.jpg";//23 index 22
	


	for (int i = 9; i < 23; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth - 9 * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	}
	
	
	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}


//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode
void Output::CreateSimulationToolBar() const
{
	CleartoolbarArea1();
	UI.AppMode = SIMULATION;	//Simulation Mode

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)

	//First prepare List of images for each menu item
	string MenuItemImages2[ITM_SIM_CNT];

	MenuItemImages2[ITM_SIM] = "images\\Menu\\Menu_Simulate.jpg";
	MenuItemImages2[ITM_TRUTH] = "images\\Menu\\Menu_Truth.jpg";
	MenuItemImages2[ITM_SAVE_Simulate] = "images\\Menu\\Menu_SAVE.jpg";
	MenuItemImages2[ITM_LOAD_Simulate] = "images\\Menu\\Menu_LOAD.jpg";
	MenuItemImages2[ITM_SWITCH_DSN] = "images\\Menu\\Menu_Design.jpg";
	MenuItemImages2[ITM_2EXIT] = "images\\Menu\\Menu_Exit.jpg";

	//TODO: Prepare image for each menu item and add it to the list

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(MenuItemImages2[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);


	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//

void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\Gate_AND2_Hi.jpg";
	else
		GateImage = "Images\\Gates\\Gate_AND2.jpg";

	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}

//TODO: Add similar functions to draw all components

//TODO: Add similar functions to draw all components
void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\2nand_h.jpg";
	else
		GateImage = "Images\\Gates\\2nand.jpg";

	//Draw NAND2 Gate at Gfx_Info (1st corner)
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\2or_h.jpg";
	else
		GateImage = "Images\\Gates\\2or.jpg";

	//Draw OR2 Gate at Gfx_Info (1st corner)
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\2nor_h.jpg";
	else
		GateImage = "Images\\Gates\\2nor.jpg";

	//Draw NOR2 Gate at Gfx_Info (1st corner)
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\2xor_h.jpg";
	else
		GateImage = "Images\\Gates\\2xor.jpg";

	//Draw XOR2 Gate at Gfx_Info (1st corner)
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\2xnor_h.jpg";
	else
		GateImage = "Images\\Gates\\2xnor.jpg";

	//Draw XNOR2 Gate at Gfx_Info (1st corner)
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawInverter(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\not_h.jpg";
	else
		GateImage = "Images\\Gates\\not.jpg";

	//Draw Inverter Gate at Gfx_Info (1st corner)
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawBuffer(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\buffer_h.jpg";
	else
		GateImage = "Images\\Gates\\buffer.jpg";

	//Draw Buffer Gate at Gfx_Info (1st corner)
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\3and_h.jpg";
	else
		GateImage = "Images\\Gates\\3and.jpg";

	//Draw AND3 Gate at Gfx_Info (1st corner)
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\3nor_h.jpg";
	else
		GateImage = "Images\\Gates\\3nor.jpg";

	//Draw NOR3 Gate at Gfx_Info (1st corner)
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\3xor_h.jpg";
	else
		GateImage = "Images\\Gates\\3xor.jpg";

	//Draw XOR3 Gate at Gfx_Info (1st corner)
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawSWITCH0(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\switch0_h.jpg";
	else
		GateImage = "Images\\Gates\\switch0.jpg";

	//Draw SWITCH at Gfx_Info (1st corner)
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawLED0(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\lamp0_h.jpg";
	else
		GateImage = "Images\\Gates\\lamp0.jpg";

	//Draw LED at Gfx_Info (1st corner)
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawSWITCH1(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\switch1_h.jpg";
	else
		GateImage = "Images\\Gates\\switch1.jpg";

	//Draw SWITCH at Gfx_Info (1st corner)
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}
void Output::DrawLED1(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\Gates\\lamp1_h.jpg";
	else
		GateImage = "Images\\Gates\\lamp1.jpg";

	//Draw LED at Gfx_Info (1st corner)
	pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.AND2_Width, UI.AND2_Height);
}


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool selected) const
{
	pWind->SetPen(BLUE, 3);
	//TODO: Add code to draw connection
	if (selected)
	{
		pWind->SetPen(RED, 3);
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y1);
		pWind->DrawLine(r_GfxInfo.x2, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
		pWind->SetPen(BLUE, 3);
	}
	else
	{
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y1);
		pWind->DrawLine(r_GfxInfo.x2, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
	}
}

Output::~Output()
{
	delete pWind;
}
