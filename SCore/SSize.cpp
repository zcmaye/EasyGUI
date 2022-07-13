#include "SSize.h"

SSize::SSize()
	:SSize(0,0)
{
}

SSize::SSize(int w, int h)
	:m_w(w)
	,m_h(h)
{
}

void SSize::setWidth(int w)
{
	m_w = w;
}

void SSize::setheight(int h)
{
	m_h = h;
}

int SSize::getWidth() const
{
	return m_w;
}

int SSize::getHeight() const
{
	return m_h;
}

bool SSize::isNull()
{
	return m_w == 0 && m_h == 0;
}
