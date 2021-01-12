#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	copy = false;
	m_GfxInfo = r_GfxInfo;	
}

Component::Component()
{}
// function take point and determine if user clicked on component or not
Component* Component::ComponentRegion(int x, int y)
{ // return pointer if point is located in area of component on output interface or return NULL
	if (x > m_GfxInfo.x1 && x < m_GfxInfo.x2 && y > m_GfxInfo.y1 && y < m_GfxInfo.y2) {
		return this;
	}
	else
	{
		return NULL;
	}
}
Component* Component::get_component(int id)
{
	if (ID == id)
	{
		return this;
	}
	else
	{
		return NULL;
	}
}
// Change Graphics info to move component 
void Component::set_GraphicsInfo(GraphicsInfo r_GfxInfo) {

	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.y2 = r_GfxInfo.y2;
	
}

GraphicsInfo Component::get_GraphicsInfo()
{
	return m_GfxInfo;
}
Component::~Component()
{}

bool Component::get_selected()
{
	return selected;
}
void Component::set_selected(bool x)
{
	selected = x;
}
void Component::setlable(string x)
{
	m_Label = x;
}

void Component::setcopy(bool x) {
	copy = x;
}
bool Component::getcopy() {
	return copy;
}
void Component::drawlable(Output* p, string s, int x, int y) {
	p->Drawlable(s, x, y);
}