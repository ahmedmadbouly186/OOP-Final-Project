#include "Deletecomp.h"
#include "..\ApplicationManager.h"
#include "../Components/Gate.h"
#include "../Components/LED.h"
#include "../Components/switch_key.h"
Deletecomp::Deletecomp(ApplicationManager* pApp) :Action(pApp)
{

}
void Deletecomp::ReadActionParameters()
{

}

void Deletecomp::Execute()
{
	pManager->Delete();
}
void Deletecomp::Undo()
{
}

void Deletecomp::Redo()
{
}
Deletecomp::~Deletecomp(void)
{
}