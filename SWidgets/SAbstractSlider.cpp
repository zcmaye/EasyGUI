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
	updateRatio();
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
	updateRatio();
}

void SAbstractSlider::setValue(int val)
{
	m_value = val;
	if (orientation() == EasyGUI::Horizontal)
	{
		m_handleRect.setX(d->x + m_value * m_ratio );
	}
	else if (orientation() == EasyGUI::Vertical)
	{
		m_handleRect.setY(d->y + m_value * m_ratio);
	}

}

void SAbstractSlider::setMaximum(int max)
{
	m_max = max;
	updateRatio();
}

void SAbstractSlider::setMinimum(int min)
{
	m_min = min;
	updateRatio();
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
		//��������
		painter.drawRect(d->x, d->y + d->h / 3, d->w, d->h / 3);
		//�����ֱ�
		painter.drawEllipse(m_handleRect);
	}
	else if (m_orientation == EasyGUI::Vertical)
	{
		//��������
		painter.drawRect(d->x + d->w / 3, d->y, d->w / 3, d->h);
		//�����ֱ�
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
#if 1
		if (m_orientation == EasyGUI::Horizontal)
		{
			//�ƶ�����
			m_handleRect.setX(msg->x - m_handleRect.width() / 2);
			//�޶�����Ļ���λ��
			if (m_handleRect.x() < d->x)
			{
				m_handleRect.setX(d->x);
			}
			else if (m_handleRect.rightTop().x() > d->x + d->w)
			{
				m_handleRect.setX(geometry().rightTop().x() - m_handleRect.width());
			}
			//�����ƶ���ʱ�򣬸ı�����
			m_distance = m_handleRect.x() - d->x;		//���鵱ǰ��������ľ���
		}
		else if (m_orientation == EasyGUI::Vertical)
		{
			m_handleRect.setY(msg->y - m_handleRect.height() / 2);
			if (m_handleRect.leftTop().y() <= d->y)
			{
				m_handleRect.setY(d->y);
			}
			else if (m_handleRect.leftBottom().y() > d->y + d->h)
			{
				m_handleRect.setY(d->y + d->h - m_handleRect.height());
			}
			m_distance = m_handleRect.y() - d->y;		//���鵱ǰ��������ľ���
		}

		//����m_distance�����ǰֵ
		//if ((int)m_ratio != 0 && m_distance % (int)m_ratio == 0)
		{
			m_value = m_distance / m_ratio;
			sclog << m_value << std::endl;
		}	
#endif
	}
}

void SAbstractSlider::moveEvent(ExMessage* msg)
{
	int minLen = min(d->w, d->h);
	m_handleRect = SRect(d->x, d->y, minLen, minLen);
}

void SAbstractSlider::updateRatio()
{
	int avaLen = max(d->w, d->h) - min(d->w, d->h);	//������Ч���ȣ����أ�
	m_ratio = (double)avaLen / (m_max - m_min);		//m_valueÿ�仯1,�����ƶ�����������	
}
