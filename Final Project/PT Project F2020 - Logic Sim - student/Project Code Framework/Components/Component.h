#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include<fstream>

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
protected:
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	bool selected; // data member used to know if component is selected or not
	int ID; // data member ID to make each component has its owned ID to simplfiy save & load Operation
	bool copy;

public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	virtual Component* get_component(int);
	virtual void set_GraphicsInfo(GraphicsInfo);
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	GraphicsInfo get_GraphicsInfo();
	Component();
	// function take point and determine if user clicked on component or not
	Component* ComponentRegion(int ,int );
	bool get_selected();
	void set_selected(bool x);
	string get_label()
	{
		return m_Label;
	}
	// save function to each component 
	virtual void save(ofstream&) = 0;
	// getter for ID   , no setter
	virtual int get_ID()
	{
		return ID;
	}
	void set_label(string x)
	{
		m_Label = x;
	}
	void setlable(string x);
	//Destructor must be virtual
	virtual ~Component();

	void setcopy(bool x);
	bool getcopy();
	void drawlable(Output* p, string s, int x, int y);

};

#endif
