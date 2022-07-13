#include "SSlider.h"
#include "SPainter.h"
SSlider::SSlider(SWidget* parent)
	:SAbstractSlider(parent)
{
	setFixedSize(200, 10);
}

void SSlider::paintEvent(ExMessage* msg)
{
	SPainter painter;
	//��������
	painter.drawRect(d->x, d->y, d->w, d->h);
	//�����ֱ�
	painter.drawEllipse(m_handleRect);
}
