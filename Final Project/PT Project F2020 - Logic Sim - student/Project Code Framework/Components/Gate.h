#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate:public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	bool* isconnected;      // array of bool to check if pin is connected or not 
	int m_Inputs;		//No. of input pins of that Gate.
public:
	Gate(int r_Inputs, int r_FanOut,int id);
	OutputPin* getoutputpin() {
		return &m_OutputPin;
	}
	InputPin* getinputpin(int n) {
		if (n < m_Inputs) {
			return &m_InputPins[n];
		}
	}
	int no_inputs()
	{
		return m_Inputs;
	}
	bool Isconnectto(int);
	void set_connection(bool,int);
	virtual void save(ofstream&)=0;

};

#endif
