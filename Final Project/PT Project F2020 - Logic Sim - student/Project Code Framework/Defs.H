#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ComponentType // componenet type for save and load operationss
{
	And2,
	Buffer,
	Inverter,
	Led,
	Nand2,
	Nor2,
	Nor3,
	Switch,
	Xnor2,
	Xor2,
	Xor3,
	And3,
	Or2,
	connection // ALL connections that would be saved

};

enum ActionType
{
	ADD_Gate,
	LOAD,		//Load a Circuit from a file
	SAVE,		//Save the whole Circuit to a file
	COPY,
	CUT,
	PASTE,
	DEL,		//Delete a Component, a Connection
	ADD_CONNECTION, //Add Wire Connection
	EXIT,		//Exit the application


	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,    //Add 2-input XNOR gate
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,		//Add 3-input XOR gate
	ADD_LED,			//Add LED
	ADD_Switch,			//Add Switch
	close,              // close the bar and return to the menu bar 



	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	Change_Switch,		//Change Switch Status in Simulation Mode

	SELECT,		//Select a Component, a Connection
	MOVE,		//Move a Component, a Connection



	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode


	STATUS_BAR,		//A click on the status bar



	DSN_TOOL,	//A click on an empty place in the design tool bar
	SIM_TOOL,

};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};


enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	ITM_ADD,
	ITM_Simulate,

	ITM_LOAD,
	ITM_SAVE,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_MOVE,
	ITM_EDITLABLE,
	ITM_Delet,
	ITM_Connection,
	ITM_EXIT,		//Exit item

	ITM_Buff,
	ITM_INV,
	ITM_AND2,		//AND gate item in menu
	ITM_OR2,		//OR gate item in menu
	ITM_NAND2,
	ITM_NOR2,
	ITM_XOR2,
	ITM_XNOR2,
	ITM_AND3,
	ITM_NOR3,
	ITM_XOR3,
	ITM_LED,
	ITM_Switch,
	ITM_Close,


	//TODO: Add more items names here
	ITM_DSN_CNT,	//no. of design menu items ==> This should be the last line in this enum

};


enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_SIM,           	//Simulate circuit
	ITM_SWITCH_DSN,   // Change to design mode
	ITM_SAVE_Simulate, // save circuit
	ITM_LOAD_Simulate,  // load circuit
	ITM_Change_Switch,    // chnage switch status
	ITM_2EXIT,
	//TODO:Add more items names here

	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum

};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	AND2_FANOUT = 5	//Default fan out of 2-input AND gate
};

//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1, y1, x2, y2;
};

#ifndef NULL
#define NULL 0
#endif

#endif