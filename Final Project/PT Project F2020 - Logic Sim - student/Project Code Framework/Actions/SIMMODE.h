

#include "action.h"
#include "..\Components\Component.h"

class SIMMODE : public Action
{
private:
	//pointer to output class
	//to control clear the tool bar
	//and return to  the menu bar
	//Output* pout;
public:
	SIMMODE(ApplicationManager* pApp);
	virtual ~SIMMODE(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

