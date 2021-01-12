#include "Connection.h"

Connection::Connection(const GraphicsInfo &r_GfxInfo, OutputPin *pSrcPin,InputPin *pDstPin,int id1,int id2, int pin_no):Component(r_GfxInfo)
	
{
	ID1 = id1;
	ID2 = id2;
	inputpin_no = pin_no;
	set_selected(false);
	SrcPin = pSrcPin;
	DstPin = pDstPin;
}
void Connection::setSourcePin(OutputPin *pSrcPin)
{	SrcPin = pSrcPin;	}

OutputPin* Connection::getSourcePin()
{	return SrcPin;	}


void Connection::setDestPin(InputPin *pDstPin)
{	DstPin = pDstPin;	}

InputPin* Connection::getDestPin()
{	return DstPin;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus(/*(STATUS)*/SrcPin->getStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo,selected);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}
int Connection::get_ID1()
{
	return ID1;
}
int Connection::get_ID2()
{
	return ID2;
}
void Connection::set_Point1(int x1,int y1)
{
	m_GfxInfo.x1 = x1;
	m_GfxInfo.y1 = y1;

}
void Connection::set_Point2(int x2, int y2)
{
	m_GfxInfo.x2 = x2;
	m_GfxInfo.y2 = y2;

}
void Connection::save(ofstream& outputfile)
{
	outputfile << ID1<<" "<< ID2<<" "<<inputpin_no <<endl;
}