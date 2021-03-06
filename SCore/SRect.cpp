#include "SRect.h"

SRect::SRect()
	:SRect(0,0,0,0)
{
}

SRect::SRect(int x, int y, int w, int h)
	:m_x(x),m_y(y),m_w(w),m_h(h)
{
}

SRect::SRect(const SPoint& leftTop, const SPoint& rightBottom)
	:SRect(leftTop.x(),leftTop.y(),rightBottom.x(),rightBottom.y())
{
}

SRect::SRect(const SPoint& leftTop, const SSize& size)
	: SRect(leftTop.x(), leftTop.y(), leftTop.x()+size.width(), leftTop.y()+size.height())
{
}

SPoint SRect::leftTop()const
{
	return SPoint(m_x,m_y);
}

SPoint SRect::leftBottom() const
{
	return SPoint(m_x, m_y + m_h);
}

SPoint SRect::rightTop() const
{
	return SPoint(m_x + m_w, m_y);
}

SPoint SRect::rightBottom()const
{
	return SPoint(m_x+m_w,m_y+m_h);
}

SPoint SRect::center() const
{
	return SPoint(m_x + m_w / 2, m_y + m_h / 2);
}

SSize SRect::size()const
{
	return SSize(m_w,m_h);
}

int SRect::width() const
{
	return m_w;
}

int SRect::height() const
{
	return m_h;
}

void SRect::setLeft(int x)
{
	setX(x);
}

void SRect::setTop(int y)
{
	setY(y);
}

void SRect::setX(int x)
{
	m_x = x;
}

void SRect::setY(int y)
{
	m_y = y;
}

void SRect::setLeftTop(const SPoint& pos)
{
	setX(pos.x());
	setY(pos.y());
}

void SRect::setLeftBottom(const SPoint& pos)
{
	m_h = m_w + pos.y() - m_y;
}

void SRect::moveCenter(const SPoint& pos)
{
	m_x = pos.x() - m_w / 2;
	m_y = pos.y() - m_h / 2;
}

void SRect::translate(int dx, int dy)
{
	m_x += dx;
	m_y += dy;
}

bool SRect::contains(const SPoint& pos)
{
	return contains(pos.x(),pos.y());
}

bool SRect::contains(int x, int y)
{
	return (x > m_x && x<m_x + m_w && y> m_y && y < m_y + m_h);
}

std::ostream& operator<<(std::ostream& out, const SRect& rect)
{
	out << "SRect(" << rect.m_x<<"," << rect.m_y<<" " << rect.m_w<<"*" << rect.m_h << ")";
	return out;
}
