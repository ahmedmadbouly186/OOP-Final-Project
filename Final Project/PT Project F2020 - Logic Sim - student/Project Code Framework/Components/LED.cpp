#include "LED.h"
LED::LED(const GraphicsInfo& r_GfxInfo,int id) 
{
	m_InputPins.setComponent(this);
	set_selected(false);
	ID = id;
	isconnected = false;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void LED::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	if (GetInputPinStatus(1) == 1) {
		x = 1;
	}
	else
	{
		x = 0;
	}
	//Add you code here
}


// Function Draw
// Draws LED 
void LED::Draw(Output* pOut)
{
	if (x == 1) {
		//Call output class and pass gate drawing info to it.
		pOut->DrawLED1(m_GfxInfo, selected);
	}
	else
	{
		pOut->DrawLED0(m_GfxInfo, selected);
	}
}

//returns status of outputpin
int LED::GetOutPinStatus()
{
	return -1;
}



bool LED::Isconnectto()
{
	if (isconnected == false)
	{
		return false;
	}
	else
	{
		return true;
	}
}
void LED::set_connection(bool b)
{
	isconnected = b;
}
//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPins.getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins.setStatus(s);
}
InputPin* LED::getinputpin()
{
	return &m_InputPins;
}
void LED::save(ofstream&  outputfile)
{
	outputfile << Led << " " << ID << " " << get_label() << " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
}
