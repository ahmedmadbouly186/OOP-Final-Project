#include "action.h"
//#include "..\Components\Component.h"

class AddGate : public Action
{
private:
	//pointer to output class
	//to control clear the Menu bar 
	//and creat the tool bar
	//Output* pout;

public:
	AddGate(ApplicationManager* pApp);
	virtual ~AddGate(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

