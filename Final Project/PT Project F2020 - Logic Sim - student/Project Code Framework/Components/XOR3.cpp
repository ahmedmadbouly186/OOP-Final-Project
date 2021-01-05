#include "XOR3.h"

XOR3::XOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut,int id) :Gate(3, r_FanOut,id)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR3::Operate()
{
	//caclulate the output status as the ANDing of the three input pins
	if (GetInputPinStatus(1) == LOW && GetInputPinStatus(2) == LOW && GetInputPinStatus(3) == LOW)
	{
		m_OutputPin.setStatus(LOW);
	}
	else if(GetInputPinStatus(1) == LOW && GetInputPinStatus(2) == LOW && GetInputPinStatus(3) == HIGH)
	{
		m_OutputPin.setStatus(HIGH);
	}
	else if (GetInputPinStatus(1) == LOW && GetInputPinStatus(2) == HIGH && GetInputPinStatus(3) == LOW)
	{
		m_OutputPin.setStatus(HIGH);
	}
	else if (GetInputPinStatus(1) == LOW && GetInputPinStatus(2) == HIGH && GetInputPinStatus(3) == HIGH)
	{
		m_OutputPin.setStatus(LOW);
	}
	else if (GetInputPinStatus(1) == HIGH && GetInputPinStatus(2) == LOW && GetInputPinStatus(3) == LOW)
	{
		m_OutputPin.setStatus(HIGH);
	}
	else if (GetInputPinStatus(1) == HIGH && GetInputPinStatus(2) == LOW && GetInputPinStatus(3) == HIGH)
	{
		m_OutputPin.setStatus(LOW);
	}
	else if (GetInputPinStatus(1) == HIGH && GetInputPinStatus(2) == HIGH && GetInputPinStatus(3) == LOW)
	{
		m_OutputPin.setStatus(LOW);
	}
	else if (GetInputPinStatus(1) == HIGH && GetInputPinStatus(2) == HIGH && GetInputPinStatus(3) == HIGH)
	{
		m_OutputPin.setStatus(HIGH);
	}

	//Add you code here
}


// Function Draw
// Draws 2-input AND gate
void XOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR3(m_GfxInfo, selected);
}

//returns status of outputpin
int XOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void XOR3::save(ofstream& outputfile)
{
	outputfile << Xor3 << " " << ID << " " << get_label() << " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
}