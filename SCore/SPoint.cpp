#include "SPoint.h"

SPoint::SPoint()
	:SPoint(0,0)
{
}

SPoint::SPoint(int x, int y)
	:m_x(x)
	,m_y(y)
{
}

void SPoint::setX(int x)
{
	m_x = x;
}

void SPoint::setY(int y)
{
	m_y = y;
}

int SPoint::x() const
{
	return m_x;
}

int SPoint::y() const
{
	return m_y;
}

bool SPoint::isNull()
{
	return m_x == 0&& m_y ==0;
}

std::ostream& operator<<(std::ostream& out, const SPoint& pos)
{
	out << "SPoint(" << pos.m_x << "," << pos.m_y << ") ";
	return  out;
}
