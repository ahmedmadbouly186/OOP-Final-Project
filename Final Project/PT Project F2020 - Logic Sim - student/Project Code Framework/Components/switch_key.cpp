#include "switch_key.h"
switch_key::switch_key(const GraphicsInfo& r_GfxInfo, int r_FanOut) :m_OutputPin(r_FanOut)
{
	set_selected(false);
	closed = false;
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}
void switch_key::Operate()
{
	/*if (closed == true)
	{
		m_outputpin.setstatus(HIGH);
	}
	else
	{
		m_outputpin.setstatus(LOW);
	}*/
}
void switch_key::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	if (closed == true)
	{
		pOut->DrawSWITCH1(m_GfxInfo, selected);
	}
	else
	{
		pOut->DrawSWITCH0(m_GfxInfo, selected);
	}
}

//returns status of outputpin
int switch_key::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}
int switch_key::GetInputPinStatus(int n)
{
	return -1;	//n starts from 1 but array index starts from 0.
}
void switch_key::setInputPinStatus(int n, STATUS s)
{
}
OutputPin switch_key::getoutputpin()
{
	return m_OutputPin;
}
bool switch_key::get_close()
{
	return closed;
}
void switch_key::set_close(bool x)
{
	closed = x;
}