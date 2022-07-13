#include "SPushButton.h"
#include "SAbstractSlider.h"
#include "SPainter.h"
#include<iostream>
SAbstractSlider::SAbstractSlider(SWidget* parent)
	:SWidget(parent)
	, m_orientation(EasyGUI::Horizontal)
{
	setMouseTracking(true);
	setFixedSize(150, 20);
	int m = min(d->w, d->h);
	m_handleRect = SRect(d->x, d->y, m,m);
}

void SAbstractSlider::setOrientation(EasyGUI::Orientation ori)
{
	if (ori == EasyGUI::Horizontal && m_orientation == EasyGUI::Vertical
		|| ori == EasyGUI::Vertical && m_orientation == EasyGUI::Horizontal)
	{
		int t = d->w;
		d->w = d->h;
		d->h = t;
	}
	m_orientation = ori;
}

EasyGUI::Orientation SAbstractSlider::orientation() const
{
	return m_orientation;
}

void SAbstractSlider::setRange(int min, int max)
{
	m_max = max;
	m_min = min;
}

void SAbstractSlider::setValue(int val)
{
	m_value = val;
}

void SAbstractSlider::setMaximum(int max)
{
	m_max = max;
}

void SAbstractSlider::setMinimum(int min)
{
	m_min = min;
}

int SAbstractSlider::maximum() const
{
	return m_max;
}

int SAbstractSlider::minimum() const
{
	return m_min;
}

void SAbstractSlider::paintEvent(ExMessage* msg)
{
	SPainter painter;
	if (m_orientation == EasyGUI::Horizontal)
	{
		//画出凹槽
		painter.drawRect(d->x, d->y + d->h / 3, d->w, d->h / 3);
		//画出手柄
		painter.drawEllipse(m_handleRect);
	}
	else if (m_orientation == EasyGUI::Vertical)
	{
		//画出凹槽
		painter.drawRect(d->x + d->w / 3, d->y, d->w / 3, d->h);
		//画出手柄
		painter.drawEllipse(m_handleRect);
	}
}

void SAbstractSlider::mousePressEvent(ExMessage* msg)
{
	if (m_handleRect.contains(msg->x, msg->y))
	{
		m_isPressHandle = true;
	}
}

void SAbstractSlider::mouseReleaseEvent(ExMessage* msg)
{
	m_isPressHandle = false;
}

void SAbstractSlider::mouseMoveEvent(ExMessage* msg)
{
	if (m_isPressHandle)
	{
		if (m_orientation == EasyGUI::Horizontal)
		{
			m_handleRect.setX(msg->x - m_handleRect.width() / 2);
			if (m_handleRect.leftTop().getX() < d->x)
			{
				m_handleRect.setX(d->x);
			}
			else if (m_handleRect.rightTop().getX() > d->x + d->w)
			{
				m_handleRect.setX(d->x + d->w - m_handleRect.width());
			}
			else  //正常移动的时候，改变数据
			{
				int w = d->w - min(d->w, d->h);	//滑块有效长度（像素）
				double ds = (double)w / (m_max - m_min);	//m_value每变化1,滑块移动的像素数量
				sclog << w << " " << ds<<" dis"<<m_distance << std::endl;
				if (m_distance % (int)ds == 0)
				{
					m_value = m_distance / ds;
				}

				if (m_distance <= 0)
				{
					m_value = m_min;
				}
				else if (m_distance >= w)
				{
					m_value = m_max;
				}


				//保存上次的距离
				m_distance = msg->x - d->x - min(d->w, d->h);
				sclog << m_value << std::endl;
			}
		}
		else if (m_orientation == EasyGUI::Vertical)
		{
			m_handleRect.setY(msg->y - m_handleRect.height()/2);
			if (m_handleRect.leftTop().getY() <= d->y)
			{
				m_handleRect.setY(d->y);
			}
			else if (m_handleRect.leftBottom().getY() > d->y + d->h)
			{
				m_handleRect.setY(d->y + d->h - m_handleRect.height());
			}
		}
	}
}

void SAbstractSlider::moveEvent(ExMessage* msg)
{
	int m = min(d->w, d->h);
	m_handleRect = SRect(d->x, d->y, m, m);
}
