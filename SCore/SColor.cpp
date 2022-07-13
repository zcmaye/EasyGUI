#include "SColor.h"

SColor::SColor()
	:SColor(0,0,0,0)
{
}

SColor::SColor(uint8 r, uint8 g, uint8 b, uint8 a)
	:m_r(r), m_g(g), m_b(b), m_a(a)
{
}

SColor::SColor(uint32 rgb)
	:m_r(GetRValue(rgb)),  m_g(GetGValue(rgb))
	 ,m_b(GetBValue(rgb)),  m_a(255)
{
	
}

uint32 SColor::toColorRef() const
{
	return RGB(m_r,m_g,m_b);
}
