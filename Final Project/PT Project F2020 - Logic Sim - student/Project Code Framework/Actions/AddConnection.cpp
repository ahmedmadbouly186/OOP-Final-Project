#include "AddConnection.h"
#include "..\ApplicationManager.h"
#include "Action.h"
#include "..\Components\Gate.h"
#include "..\Components\LED.h"
#include "..\Components\switch_key.h"

AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{}

AddConnection::~AddConnection(void)
{
}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("connection: Click on first component you want to connect");

	//Wait for User Input
	pIn->GetPointClicked(x1,y1);

	pOut->ClearStatusBar();

	pOut->PrintMsg("connection: Click on second component you want to connect");

	pIn->GetPointClicked(x2, y2);
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddConnection::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	GraphicsInfo M_GfxInfo;
	OutputPin* outpin = NULL;                                 // pointer to get outputpin of component
	InputPin* inpin=NULL;                                     // pointer to get inputpin of component
	Component* component = pManager->ComponentRegion(x1, y1); // get component that user clicked on 
	int id1, id2, n;                                          // integrs to have information of component 
	if (component != NULL)
	{
		Gate* g = dynamic_cast<Gate*>(component); // dynamic cast to know type of component if gate or led or switch
		if (g != NULL)
		{
			GraphicsInfo m_GfxInfo1 = g->get_GraphicsInfo(); // get GraphicsInfo of component to knoe location of connection 
			if (x1 > m_GfxInfo1.x1 + UI.AND2_Width / 2) {
				outpin = g->getoutputpin();        // get pointer to outputpin defined in each component
				M_GfxInfo.x1 = m_GfxInfo1.x2;
				M_GfxInfo.y1 = m_GfxInfo1.y2 - UI.AND2_Width / 2; // calculate info of connection
				id1 = g->get_ID();   // get id of component to be saved to connection (help in save and load )
			}
			else
			{
				id2 = g->get_ID();
				int m = g->no_inputs();
				M_GfxInfo.x2 = m_GfxInfo1.x1;
				if (m == 1) {
					
						inpin = g->getinputpin(m - 1);
						n = m;
						M_GfxInfo.y2 = m_GfxInfo1.y2 - UI.AND2_Width / 2;
					
				}
				else if (m == 2) {
					if (y1 < m_GfxInfo1.y1 + (UI.AND2_Height / 2)) {
							inpin = g->getinputpin(m - 2);
							n = m - 1;
							M_GfxInfo.y2 = m_GfxInfo1.y2 - (2* UI.AND2_Width / 3);
						
					}
					else {
							inpin = g->getinputpin(m - 1);
							n = m;
							M_GfxInfo.y2 = m_GfxInfo1.y2 -   UI.AND2_Width / 3;
						
					}
				}
				else
				{
					if (y1 < m_GfxInfo1.y1 + UI.AND3_Height / 3) {
							inpin = g->getinputpin(m - 3);
							n = m - 2;
							M_GfxInfo.y2 = m_GfxInfo1.y1 + UI.AND3_Width / 4;
						
					}
					else if (y1 > m_GfxInfo1.y1 + UI.AND3_Height / 3 && y1 < m_GfxInfo1.y1 + 2 * UI.AND3_Height / 3) {
							inpin = g->getinputpin(m - 2);
							n = m - 1;
							M_GfxInfo.y2 = m_GfxInfo1.y1 + UI.AND3_Width / 2;
						
					}
					else
					{
						
						n = m;
						inpin = g->getinputpin(m - 1);
						M_GfxInfo.y2 = m_GfxInfo1.y1 +3* UI.AND3_Width / 4;
					}
				}
			}
		}
		switch_key* Switch = dynamic_cast<switch_key*>(component); // same code but for switch 
		if (Switch != NULL)
		{
			id1 =  Switch->get_ID();
			GraphicsInfo m_GfxInfo1 = Switch->get_GraphicsInfo();
			outpin = Switch->getoutputpin();
			M_GfxInfo.x1 = m_GfxInfo1.x2;
			M_GfxInfo.y1 = m_GfxInfo1.y2 - UI.SWITCH0_Height / 2;

		}
		LED* led = dynamic_cast<LED*>(component); // same code but for led
		if (led != NULL)
		{
			id2 = led->get_ID();
			GraphicsInfo m_GfxInfo1 = led->get_GraphicsInfo();
			n = 1;
			inpin = led->getinputpin();
			M_GfxInfo.x2 = m_GfxInfo1.x2;
			M_GfxInfo.y2 = m_GfxInfo1.y2 - UI.LED0_Height / 4;
		}
	}
	component = pManager->ComponentRegion(x2, y2); // second for loop to know second component 
	if (component != NULL)
	{
		Gate* g = dynamic_cast<Gate*>(component);
		if (g != NULL)
		{
			int m = g->no_inputs();
			GraphicsInfo m_GfxInfo1 = g->get_GraphicsInfo();
			if (x2 > m_GfxInfo1.x1 + UI.AND2_Width / 2) {
				outpin = g->getoutputpin();
				M_GfxInfo.x1 = m_GfxInfo1.x2;
				M_GfxInfo.y1 = m_GfxInfo1.y2 - UI.AND2_Width / 2;
				id1 = g->get_ID();
			}
			else
			{
				id2 = g->get_ID();
				M_GfxInfo.x2 = m_GfxInfo1.x1;
				if (m == 1) {
						inpin = g->getinputpin(m - 1);
						n = m;
						M_GfxInfo.y2 = m_GfxInfo1.y2 - UI.AND2_Width / 2;
					
				}
				else if (m == 2) {
					if (y2 < m_GfxInfo1.y1 + UI.AND2_Height / 2) {
							inpin = g->getinputpin(m - 2);
							n = m - 1;
							M_GfxInfo.y2 = m_GfxInfo1.y2 - 2 * UI.AND2_Width / 3;
						
					}
					else {
							inpin = g->getinputpin(m - 1);
							n = m;
							M_GfxInfo.y2 = m_GfxInfo1.y2 - UI.AND2_Width / 3;	
					}
				}
				else
				{
					if (y2 < m_GfxInfo1.y1 + UI.AND3_Height / 3) {
							inpin = g->getinputpin(m - 3);
							n = m - 2;
							M_GfxInfo.y2 = m_GfxInfo1.y1 + UI.AND3_Width / 4;
					}
					else if (y2 > m_GfxInfo1.y1 + UI.AND3_Height / 3 && y2 < m_GfxInfo1.y1 + 2 * UI.AND3_Height / 3) {
							inpin = g->getinputpin(m - 2);
							n = m - 1;
							M_GfxInfo.y2 = m_GfxInfo1.y1 + UI.AND3_Width / 2;
						
					}
					else
					{
							n = m;
							inpin = g->getinputpin(m - 1);
							M_GfxInfo.y2 = m_GfxInfo1.y1 +3* UI.AND3_Width / 4;	
					}
				}
			}
		}
		switch_key* Switch = dynamic_cast<switch_key*>(component);
		if (Switch != NULL)
		{
			id1 = Switch->get_ID();
			GraphicsInfo m_GfxInfo1 = Switch->get_GraphicsInfo();
			outpin = Switch->getoutputpin();
			M_GfxInfo.x1 = m_GfxInfo1.x2;
			M_GfxInfo.y1 = m_GfxInfo1.y2 - UI.SWITCH0_Height / 2;
		}
		LED* led = dynamic_cast<LED*>(component);
		if (led != NULL)
		{
			id2 = led->get_ID();
			GraphicsInfo m_GfxInfo1 = led->get_GraphicsInfo();
			n = 1;
			inpin = led->getinputpin();
			M_GfxInfo.x2 = m_GfxInfo1.x1;
			M_GfxInfo.y2 = m_GfxInfo1.y2 - UI.LED0_Height /4 ;
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Output* pOut = pManager->GetOutput();
	if (outpin != NULL && inpin != NULL) {  // check if connections is correct (connected to input and outpin pin or falied to add connection)
		Gate* gate = dynamic_cast<Gate*>(pManager->load_connection(id2)); // fucnction to know component from its id
		LED* led = dynamic_cast<LED*>(pManager->load_connection(id2));
		if (gate != NULL)
		{
			if (!gate->Isconnectto(n)) {    // function to know if gate has already connection to pin number n or not 
				gate->set_connection(true, n-1);
				Connection* pA = new Connection(M_GfxInfo, outpin, inpin, id1, id2, n);
				if (outpin->ConnectTo(pA)) {
					pManager->AddComponent(pA);
					pOut->PrintMsg("Connection is added");
					return;
				}
				else
				{
					pOut->PrintMsg("Falied to add connection, complete fanout for this gate");
					delete pA;
					return;
				}
				
			}
			pOut->PrintMsg("falied to add connection: already connected");
			return;
		}
		if (led != NULL)
		{
			if(!led->Isconnectto())
			{
				led->set_connection(true);
				Connection* pA = new Connection(M_GfxInfo, outpin, inpin, id1, id2, n);
				if (outpin->ConnectTo(pA)) {
					pManager->AddComponent(pA);
					pOut->PrintMsg("Connection is added");
					return;
				}
				else
				{
					pOut->PrintMsg("Falied to add connection, complete fanout for this gate");
					delete pA;
					return;
				}
			}
			pOut->PrintMsg("falied to add connection: already connected");
			return;
		}
	}
	pOut->PrintMsg("falied to add connection");
}

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}

