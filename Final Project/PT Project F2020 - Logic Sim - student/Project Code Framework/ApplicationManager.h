#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include"Components/Connection.h"
#include"Components/Gate.h"


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
	Component* cut_component;
public:
	Component* load_connection(int id1);
	void Delete();
	
public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	// function to return component that user clicked on in output interface
	Component* ComponentRegion(int ,int );

	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();
	Component* get_selected();
	Gate* get_gate();
	Connection* get_connection();
	Component* getcut_component();
	void setcut_component(Component*);
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
	void operations();
	//destructor
	~ApplicationManager();
};

#endif