

#include "action.h"
#include "..\Components\Component.h"

class Close : public Action
{
private:
	//pointer to output class
	//to control clear the tool bar
	//and return to  the menu bar
	//Output* pout;
public:
	Close(ApplicationManager* pApp);
	virtual ~Close(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

