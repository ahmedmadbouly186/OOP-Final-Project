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
	bool selected;
	int ID;
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	virtual Component* get_component(int);
	void set_GraphicsInfo(GraphicsInfo);
	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	//void setmym_Label(string s);
	//virtual InputPin* getinputpin(int n) = 0;
	//virtual OutputPin getoutputpin() = 0;
	virtual GraphicsInfo info() 
	{
		return m_GfxInfo;
	}
	GraphicsInfo get_GraphicsInfo();
	Component();
	Component* ComponentRegion(int ,int );
	bool get_selected();
	void set_selected(bool x);
	string get_label()
	{
		return m_Label;
	}
	virtual void save(ofstream&) = 0;
	int get_ID()
	{
		return ID;
	}
	void set_label(string x)
	{
		m_Label = x;
	}
	void setlable(string x);

	/*void set_id(int x)
	{
		ID = x;
	}*/
	//Destructor must be virtual
	virtual ~Component();
};

#endif
