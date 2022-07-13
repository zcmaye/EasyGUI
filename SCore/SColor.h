#ifndef _SCOLOR_H_
#define _SCOLOR_H_
#include"Configer.h"
class SColor
{
public:
	enum GlobalColor
	{
		Red = RED,
		Blue = BLUE,
		Yellow = YELLOW,
		Green = GREEN,
		Black = BLACK
	};
public:
	SColor();
	SColor(uint8 r, uint8 g, uint8 b, uint8 a = 255 );
	SColor(uint32 rgb);
	uint32 toColorRef()const;
	inline operator uint32()const { return(RGB(m_r, m_g, m_b)); };
private:
	uint8 m_r;
	uint8 m_g;
	uint8 m_b;
	uint8 m_a;
};

#endif