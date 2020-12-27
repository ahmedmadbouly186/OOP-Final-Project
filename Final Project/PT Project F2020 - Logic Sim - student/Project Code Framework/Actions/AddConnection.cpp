#include "AddConnection.h"
#include "..\ApplicationManager.h"
#include "Action.h"
#include "..\Components\Gate.h"

AddConnection::AddConnection(ApplicationManager* pApp) :Action(pApp)
{
}

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

	pOut->PrintMsg("connection: Click on second component you want to connect");

	pIn->GetPointClicked(x2, y2);
	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddConnection::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	// component list check region
	GraphicsInfo M_GfxInfo;
	OutputPin* outpin=NULL;
	InputPin* inpin;
	Component* p1 = pManager->ComponentRegion(x1,y1);
	if (p1 != NULL)
	{
		GraphicsInfo m_GfxInfo1 = ((Gate*)p1)->info();
		if (x1 > m_GfxInfo1.x1 + UI.AND2_Width / 2) {
			outpin = &((Gate*)p1)->getoutputpin();
			M_GfxInfo.x1 = m_GfxInfo1.x2;
			M_GfxInfo.y1 = (m_GfxInfo1.y1+ m_GfxInfo1.y2)/2;
		}
		else
		{
			int m= ((Gate*)p1)->no_inputs();
			if (m == 1) {
				inpin = ((Gate*)p1)->getinputpin(m-1);
				M_GfxInfo.x1 = m_GfxInfo1.x1;
				M_GfxInfo.y1 = (m_GfxInfo1.y1 + m_GfxInfo1.y2) / 2;
			}
			else if (m == 2) {
				if (y1 < m_GfxInfo1.y1 + UI.AND2_Height / 2) {
					inpin = ((Gate*)p1)->getinputpin(m - 2);
					M_GfxInfo.x1 = m_GfxInfo1.x1;
					M_GfxInfo.y1 = (m_GfxInfo1.y1 + m_GfxInfo1.y2) / 3;
				}
				else {
					inpin = ((Gate*)p1)->getinputpin(m - 1);
					M_GfxInfo.x1 = m_GfxInfo1.x1;
					M_GfxInfo.y1 = 2*(m_GfxInfo1.y1 + m_GfxInfo1.y2) / 3;
				}
			}
			else
			{
				if (y1 < m_GfxInfo1.y1 + UI.AND2_Height / 3) {
					inpin = ((Gate*)p1)->getinputpin(m - 3);
					M_GfxInfo.x1 = m_GfxInfo1.x1;
					M_GfxInfo.y1 = (m_GfxInfo1.y1 + m_GfxInfo1.y2) / 4;
				}
				else if (y1 > m_GfxInfo1.y1 + UI.AND2_Height / 3 && y1 < m_GfxInfo1.y1 + 2 * UI.AND2_Height / 3) {
					inpin = ((Gate*)p1)->getinputpin(m - 2);
					M_GfxInfo.x1 = m_GfxInfo1.x1;
					M_GfxInfo.y1 = (m_GfxInfo1.y1 + m_GfxInfo1.y2) / 2;
				}
				else
				{
					inpin = ((Gate*)p1)->getinputpin(m - 1);
					M_GfxInfo.x1 = m_GfxInfo1.x1;
					M_GfxInfo.y1 = 3 * (m_GfxInfo1.y1 + m_GfxInfo1.y2) / 4;
				}
			}
		}
	}


	Component* p2 = pManager->ComponentRegion(x2, y2);
	if (p2 != NULL)
	{
		GraphicsInfo m_GfxInfo2 = p2->info();
		if (x1 > m_GfxInfo2.x1 + UI.AND2_Width / 2) {
			outpin = &((Gate*)p2)->getoutputpin();
			M_GfxInfo.x2 = m_GfxInfo2.x2;
			M_GfxInfo.y2 = (m_GfxInfo2.y1 + m_GfxInfo2.y2) / 2;
		}
		else
		{
			int m = ((Gate*)p2)->no_inputs();
			if (m == 1) {
				inpin = ((Gate*)p2)->getinputpin(m - 1);
				M_GfxInfo.x2 = m_GfxInfo2.x1;
				M_GfxInfo.y2 = (m_GfxInfo2.y1 + m_GfxInfo2.y2) / 2;
			}
			else if (m == 2) {
				if (y1 < m_GfxInfo2.y1 + UI.AND2_Height / 2) {
					inpin = ((Gate*)p2)->getinputpin(m - 2);
					M_GfxInfo.x2 = m_GfxInfo2.x1;
					M_GfxInfo.y2 = (m_GfxInfo2.y1 + m_GfxInfo2.y2) / 3;

				}
				else {
					inpin = ((Gate*)p2)->getinputpin(m - 1);
					M_GfxInfo.x2 = m_GfxInfo2.x1;
					M_GfxInfo.y2 = 2*(m_GfxInfo2.y1 + m_GfxInfo2.y2) / 3;
				}
			}
			else
			{
				if (y1 < m_GfxInfo2.y1 + UI.AND2_Height / 3) {
					inpin = ((Gate*)p2)->getinputpin(m - 3);
					M_GfxInfo.x2 = m_GfxInfo2.x1;
					M_GfxInfo.y2 = (m_GfxInfo2.y1 + m_GfxInfo2.y2) / 4;
				}
				else if (y1 > m_GfxInfo2.y1 + UI.AND2_Height / 3 && y1 < m_GfxInfo2.y1 + 2 * UI.AND2_Height / 3) {
					inpin = ((Gate*)p2)->getinputpin(m - 2);
					M_GfxInfo.x2 = m_GfxInfo2.x1;
					M_GfxInfo.y2 = (m_GfxInfo2.y1 + m_GfxInfo2.y2) / 2;
				}
				else
				{
					inpin = ((Gate*)p2)->getinputpin(m - 1);
					M_GfxInfo.x2 = m_GfxInfo2.x1;
					M_GfxInfo.y2 = 3* (m_GfxInfo2.y1 + m_GfxInfo2.y2) / 4;

				}
			}
		}
	}
	//ReadActionParameters();
	M_GfxInfo.x1 = x1;
	M_GfxInfo.y1 = y1;
	M_GfxInfo.x2 = x2;
	M_GfxInfo.y2 = y2;
	if (p1 != NULL && p2 != NULL&& outpin != NULL && inpin != NULL) {
		
		Connection* pA = new Connection(M_GfxInfo,outpin,inpin);
		outpin->ConnectTo(pA);
		if (outpin->ConnectTo(pA)) {
			pManager->AddComponent(pA);
		}
		else
		{
			delete pA;
		}
	}


	/*
	int Len = UI.Buffer_Width;
	int Wdth = UI.Buffer_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the Buffer gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	if (GInfo.y1 > UI.ToolBarHeight && GInfo.y2 < UI.height - UI.StatusBarHeight && GInfo.x1 > 0 && GInfo.x2 < UI.width)
	{
		Connection* pA = new Connection(GInfo);
		pManager->AddComponent(pA);
	}*/
}

void AddConnection::Undo()
{}

void AddConnection::Redo()
{}


