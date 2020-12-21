#include "GUI\Input.h"
#include "GUI\Output.h"


//This is a test code to test the Input and Output classes

int main()
{
	int x, y;
	//Create Input and Output objects to test
	Output* pOut = new Output();
	Input* pIn = pOut->CreateInput();
	//Starting the test
	pOut->PrintMsg("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMsg("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	Drawing all the Components with all possible states: Normal, highlighted
	//			
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMsg("TEST2: Now we will show that Output class can draw any Component in any state, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	GraphicsInfo GfxInfo;  //to be used with draw function of the class Ouput

	/// 2.1- AND2 Gate test
	pOut->PrintMsg("Drawing 2-input AND gate, Normal and Highlighted,  Click to continue");

	//Drawing Normal AND2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawAND2(GfxInfo);

	//Drawing Highlighted AND2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawAND2(GfxInfo, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();


	/// 2.2- NAND2 Gate test
	pOut->PrintMsg("Drawing 2-input NAND gate, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw 2-input NAND gate, Normal and Highlighted
	//Drawing Normal NAND2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawNAND2(GfxInfo);

	//Drawing Highlighted NAND2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawNAND2(GfxInfo, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.3- OR2 and NOR2 Gates test
	pOut->PrintMsg("Drawing 2-input OR and NOR gates, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw 2-input OR and NOR gates, Normal and Highlighted for each
	//Drawing Normal OR2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawOR2(GfxInfo);

	//Drawing Highlighted OR2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawOR2(GfxInfo, true);
	//Drawing Normal NOR2 gate
	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->DrawNOR2(GfxInfo);

	//Drawing Highlighted NOR2 gate
	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
	pOut->DrawNOR2(GfxInfo, true);
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.4- XOR2 and XNOR2 Gates test
	pOut->PrintMsg("Drawing 2-input XOR and XNOR gates, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw 2-input XOR and XNOR gates, Normal and Highlighted for each
	//Drawing Normal XOR2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawXOR2(GfxInfo);

	//Drawing Highlighted XOR2 gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawXOR2(GfxInfo, true);
	//Drawing Normal XNOR2 gate
	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->DrawXNOR2(GfxInfo);

	//Drawing Highlighted XNOR2 gate
	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
	pOut->DrawXNOR2(GfxInfo, true);
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.5- Buffer and Inverter Gates test
	pOut->PrintMsg("Drawing Buffer and Inverter Gates, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw Buffer and Inverter Gates, Normal and Highlighted for each
	//Drawing Normal Buffer gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawBuffer(GfxInfo);

	//Drawing Highlighted Buffer gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawBuffer(GfxInfo, true);
	//Drawing Normal Inverter gate
	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->DrawInverter(GfxInfo);

	//Drawing Highlighted Inverter gate
	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
	pOut->DrawInverter(GfxInfo, true);
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();


	/// 2.6- AND3, NOR3, and XOR3 Gates test
	pOut->PrintMsg("Drawing 3-input AND, NOR, XOR Gates, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw 3-input AND, NOR, and XOR Gates, Normal and Highlighted for each
	//Drawing Normal 3-input AND gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawAND3(GfxInfo);

	//Drawing Highlighted 3-input AND gate
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawAND3(GfxInfo, true);
	//Drawing Normal 3-input NOR gate
	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->DrawNOR3(GfxInfo);

	//Drawing Highlighted 3-input NOR gate
	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
	pOut->DrawNOR3(GfxInfo, true);
	//Drawing Normal 3-input XOR gate
	GfxInfo.x1 = 300;	GfxInfo.y1 = 100;
	pOut->DrawXOR3(GfxInfo);

	//Drawing Highlighted 3-input XOR gate
	GfxInfo.x1 = 300;	GfxInfo.y1 = 200;
	pOut->DrawXOR3(GfxInfo, true);
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.7- Switch and LED test
	pOut->PrintMsg("Drawing Switch and LED, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw Switch and LED, Normal and Highlighted for each
	//Drawing Normal SWITCH
	GfxInfo.x1 = 100;	GfxInfo.y1 = 100;
	pOut->DrawSWITCH0(GfxInfo);

	//Drawing Highlighted SWITCH
	GfxInfo.x1 = 100;	GfxInfo.y1 = 200;
	pOut->DrawSWITCH0(GfxInfo, true);
	//Drawing Normal LED
	GfxInfo.x1 = 200;	GfxInfo.y1 = 100;
	pOut->DrawLED0(GfxInfo);

	//Drawing Highlighted LED
	GfxInfo.x1 = 200;	GfxInfo.y1 = 200;
	pOut->DrawLED0(GfxInfo, true);
	//Drawing Normal SWITCH
	GfxInfo.x1 = 300;	GfxInfo.y1 = 100;
	pOut->DrawSWITCH1(GfxInfo);

	//Drawing Highlighted SWITCH
	GfxInfo.x1 = 300;	GfxInfo.y1 = 200;
	pOut->DrawSWITCH1(GfxInfo, true);
	//Drawing Normal LED
	GfxInfo.x1 = 400;	GfxInfo.y1 = 100;
	pOut->DrawLED1(GfxInfo);

	//Drawing Highlighted LED
	GfxInfo.x1 = 400;	GfxInfo.y1 = 200;
	pOut->DrawLED1(GfxInfo, true);
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();


	/// 2.8- Connections
	pOut->PrintMsg("Drawing connections, Normal, Highlighted, straight, and broken,  Click to continue");

	///TODO: Add code to draw connections, Normal, Highlighted, straight, and broken (all combinations)
	GraphicsInfo r_GfxInfo;
	// normal and straight
	r_GfxInfo.x1 = 100;
	r_GfxInfo.y1 = 200;
	r_GfxInfo.x2 = 200;
	r_GfxInfo.y2 = 200;
	pOut->DrawConnection(r_GfxInfo);
	pIn->GetPointClicked(x, y);	//Wait for any click
	// Highlighted
	r_GfxInfo.x1 = 200;
	r_GfxInfo.y1 = 300;
	r_GfxInfo.x2 = 300;
	r_GfxInfo.y2 = 300;
	pOut->DrawConnection(r_GfxInfo, true);
	pIn->GetPointClicked(x, y);	//Wait for any click
	// broken
	r_GfxInfo.x1 = 400;
	r_GfxInfo.y1 = 400;
	r_GfxInfo.x2 = 500;
	r_GfxInfo.y2 = 500;
	pOut->DrawConnection(r_GfxInfo);
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->ClearDrawingArea();




	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMsg("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMsg("Testing Input ability to read strings");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar and print it inside the drawing area
	string z;
	z = pIn->GetSrting(pOut);

	pIn->GetPointClicked(x, y);	//Wait for any click

	pOut->PrintMsg("finish entering the name , click anywhere");
	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMsg("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	///TODO:  You must add a case for each action
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case ADD_Gate:
			pOut->PrintMsg("Action: close the Menu bar and go to tool bar , Click anywhere");
			pOut->CreateDesignToolBar();
			pOut->CreateDesignToolBar2();

		case UNDO:
			pOut->PrintMsg("Action: UNDO the last action , Click anywhere");
			break;

		case REDO:
			pOut->PrintMsg("Action: REDO the last UNDO , Click anywhere");
			break;

		case LOAD:
			pOut->PrintMsg("Action: LOAD your Design , Click anywhere");
			break;

		case SAVE:
			pOut->PrintMsg("Action: Save the Design , Click anywhere");
			break;

		case DEL:
			pOut->PrintMsg("Action: DEL the selected component , Click anywhere");
			break;

		case ADD_CONNECTION:
			pOut->PrintMsg("Action: ADD CONNECTION between components  , Click anywhere");
			break;

		case ADD_Buff:
			pOut->PrintMsg("Action: add a buffer gate , Click anywhere");
			break;

		case ADD_INV:
			pOut->PrintMsg("Action: add an inverter gate , Click anywhere");
			break;

		case ADD_AND_GATE_2:
			pOut->PrintMsg("Action: add 2-input AND gate , Click anywhere");
			break;

		case ADD_NAND_GATE_2:
			pOut->PrintMsg("Action: add 2-input NAND gate , Click anywhere");
			break;

		case ADD_OR_GATE_2:
			pOut->PrintMsg("Action: add 2-input OR gate , Click anywhere");
			break;

		case ADD_NOR_GATE_2:
			pOut->PrintMsg("Action: add 2-input NOR gate , Click anywhere");
			break;

		case ADD_XOR_GATE_2:
			pOut->PrintMsg("Action: add 2-input XOR gate , Click anywhere");
			break;

		case ADD_XNOR_GATE_2:
			pOut->PrintMsg("Action: add 2-input XNOR gate , Click anywhere");
			break;

		case ADD_AND_GATE_3:
			pOut->PrintMsg("Action: add 3-input AND gate , Click anywhere");
			break;

		case ADD_NOR_GATE_3:
			pOut->PrintMsg("Action: add 3-input NOR gate , Click anywhere");
			break;

		case ADD_XOR_GATE_3:
			pOut->PrintMsg("Action: add 3-input AND gate , Click anywhere");
			break;

		case ADD_LED:
			pOut->PrintMsg("Action: add LED , Click anywhere");
			break;

		case ADD_Switch:
			pOut->PrintMsg("Action: add Switch , Click anywhere");
			break;

		case close:
			pOut->PrintMsg("Action: Close Design bar and return go menu bar , Click anywhere");
			pOut->CleartoolbarArea1();
			pOut->CreateDesignToolBar();
			break;


		case DSN_TOOL:
			pOut->PrintMsg("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;


			/// 
			/// 
			/// 
			/// 

		case SIM_MODE:
			pOut->PrintMsg("Action: Switch to Simulation Mode, creating simualtion tool bar");
			pOut->CleartoolbarArea1();
			pOut->CreateSimulationToolBar();
			break;

		case Create_TruthTable:
			pOut->PrintMsg("Action: Create Truth Table for the Recent Component , creating simualtion tool bar");
			pOut->CreateSimulationToolBar();
			break;




		case DSN_MODE:
			pOut->PrintMsg("Action: Switch to Design Mode, creating Design tool bar");
			pOut->CleartoolbarArea1();
			pOut->CreateDesignToolBar();
			break;


		case SIM_TOOL:
			pOut->PrintMsg("Action: a click on empty area in the Design Tool Bar, Click anywhere");
			break;



			/// <summary>
			/// 
			/// </summary>
			/// <returns></returns>
			/// 


		case SELECT:
			pOut->PrintMsg("Action: a click on the Drawing area, Click anywhere");
			break;

		case STATUS_BAR:
			pOut->PrintMsg("Action: a click on the Status Bar, Click anywhere");
			break;


		case EXIT:
			break;
		}
	} while (ActType != EXIT);


	/// Exiting
	pOut->PrintMsg("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x, y);


	delete pIn;
	delete pOut;
	return 0;
}


