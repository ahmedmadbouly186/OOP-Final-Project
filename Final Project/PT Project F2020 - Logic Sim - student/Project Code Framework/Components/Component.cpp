#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
}

Component::Component()
{}

Component* Component::ComponentRegion(int x, int y)
{
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
/*
void Component::setmym_Label(string s)
{
	m_Label = s;
}
*/
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