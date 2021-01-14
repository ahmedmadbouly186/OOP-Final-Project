

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

