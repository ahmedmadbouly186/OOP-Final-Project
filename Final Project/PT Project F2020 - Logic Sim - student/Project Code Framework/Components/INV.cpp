#include "INV.h"

INV::INV(const GraphicsInfo& r_GfxInfo, int r_FanOut, int id) :Gate(1, r_FanOut,id)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void INV::Operate()
{
	//caclulate the output status as the ANDing of the one input pin
	if (GetInputPinStatus(1) == LOW)
	{
		m_OutputPin.setStatus(HIGH) ;
	}
	else
	{
		m_OutputPin.setStatus(LOW);
	}
	//Add you code here
}


// Function Draw
// Draws 1-input INV gate
void INV::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawInverter(m_GfxInfo, selected);
}

//returns status of outputpin
int INV::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int INV::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void INV::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void INV::save(ofstream& outputfile)
{
	outputfile << Inverter <<" "<<ID << " " << get_label() << " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
}