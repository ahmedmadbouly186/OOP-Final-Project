#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include"Components/Connection.h"


//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface
	int counter;

public:
	int get_compcount();
	Component**& get_CompList();
	Component* load_connection(int id1);
	Component* Check(int i);
	void Delete(int i);
	Connection* Check_conn(int i);
public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	// function to return component that user clicked on in output interface
	Component* ComponentRegion(int ,int );
	Component* componentreturin(int);

	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	// get unique counter to each created component 
	int get_counter()
	{
		return counter;
	}
	// function save to save components (calls save function in each component)
	void save(ofstream & outputfile);
	
	Connection* get_connections(int ,int&);
	//destructor
	~ApplicationManager();
};

#endif