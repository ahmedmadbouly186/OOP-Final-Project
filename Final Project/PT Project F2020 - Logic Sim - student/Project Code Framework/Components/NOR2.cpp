#include "NOR2.h"

NOR2::NOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut, int id) :Gate(2, r_FanOut,id)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOR2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	if (GetInputPinStatus(1) == LOW && GetInputPinStatus(2) == LOW)
	{
		m_OutputPin.setStatus(HIGH);

	}
	else
	{
		m_OutputPin.setStatus(LOW);

	}
	//Add you code here
}


// Function Draw
// Draws 2-input NOR gate
void NOR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR2(m_GfxInfo, selected);
}

//returns status of outputpin
int NOR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void NOR2::save(ofstream& outputfile)
{
	outputfile << Nor2 << " " << ID << " " << get_label() << " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << endl;
}