#include "SIM_TOOL.h"
#include"Action.h"
#include"..\ApplicationManager.h"

SIM_Tool::SIM_Tool(ApplicationManager* pApp) :Action(pApp)
{
}

SIM_Tool::~SIM_Tool(void)
{
}

void SIM_Tool::ReadActionParameters()
{

}

void SIM_Tool::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Clicked on Empty Area in Simulation bar");

}

void SIM_Tool::Undo()
{}

void SIM_Tool::Redo()
{}