#include"SPushButton.h"
#include"SPainter.h"
SPushButton::SPushButton(SWidget* parent)
	:SPushButton("PushButton",parent)
{
}

SPushButton::SPushButton(const std::string& text, SWidget* parent)
	:SWidget(parent)
	,m_text(text)
{
	d->w = 125;
	d->h = 30;

	setHoverColor(SColor(252, 252, 252));
	m_onClickedfun = nullptr;
	m_data = nullptr;
}

void SPushButton::onClicked(OnClickedFun fun,void*data)
{
	m_onClickedfun = fun;
	m_data = data;
}



void SPushButton::paintEvent(ExMessage* msg)
{
	//���ư�ť
	SWidget::paintEvent(msg);
	//�����ı�
	SPainter painter;
	painter.setPen(d->textColor);
	painter.drawText(geometry(), m_text);
}

void SPushButton::mousePressEvent(ExMessage* msg)
{
	if(m_onClickedfun)
		m_onClickedfun(m_data);
}
