#pragma once
#include"Component.h"
#include "InputPin.h"
class LED :public Component
 {
	InputPin m_InputPins;
	bool x;
	bool isconnected;
public:
	LED(const GraphicsInfo & r_GfxInfo,int id);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output * pOut);	//Draws 2-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	bool Isconnectto();
	void LED::set_connection(bool );
	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	InputPin* getinputpin();
	virtual void save(ofstream&);
};


