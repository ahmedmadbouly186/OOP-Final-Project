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