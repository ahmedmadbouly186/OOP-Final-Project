#include "XOR2.h"

XOR2::XOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut, int id) :Gate(2, r_FanOut,id)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR2::Operate()
{
	//caclulate the output status as the XOR2 of the two input pins

	//Add you code here
	if (GetInputPinStatus(1) == GetInputPinStatus(2))
	{
		m_OutputPin.setStatus(LOW);
	}
	else
	{
		m_OutputPin.setStatus(HIGH);
	}
}


// Function Draw
// Draws 2-input XOR2 gate
void XOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR2(m_GfxInfo, selected);
}

//returns status of outputpin
int XOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void XOR2::save(ofstream& outputfile)
{
	outputfile << Xor2 << " " << ID << " " << get_label() << " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
}