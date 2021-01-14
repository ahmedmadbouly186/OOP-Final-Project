#pragma once
#include "Component.h"
#include "OutputPin.h"
class switch_key :public Component
{
private:
	bool closed;
protected:
	OutputPin m_OutputPin;
public:
	switch_key(const GraphicsInfo& r_GfxInfo, int r_FanOut,int id);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s);
	bool get_close();
	void set_close(bool x);
	virtual void save(ofstream&);
	OutputPin* getoutputpin();
};
