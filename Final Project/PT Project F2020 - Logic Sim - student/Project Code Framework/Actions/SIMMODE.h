

#include "action.h"
#include "..\Components\Component.h"
#include "..\ApplicationManager.h"
#include "..\Components\Connection.h"
#include "..\Components\Gate.h"
#include "..\Components\LED.h"
#include "..\Components\switch_key.h"
#include "Action.h"
#include "..\Components\InputPin.h"
#include "..\Components\OutputPin.h"
class SIMMODE : public Action
{
private:
	//pointer to output class
	//to control clear the tool bar
	//and return to  the menu bar
	//Output* pout;
	//int x1, x2, y1, y2;

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

