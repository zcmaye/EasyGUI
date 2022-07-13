#include"SLineEdit.h"
#include "SPainter.h"
#include"../SCore/SElapsedTimer.h"
SLineEdit::SLineEdit(SWidget* parent)
	:SWidget(parent)
	, m_cursorTimer(new SElapsedTimer)
{
	d->w = 150;
	d->h = 25;

}

SLineEdit::~SLineEdit()
{
	delete m_cursorTimer;
}

void SLineEdit::paintEvent(ExMessage* msg)
{
	SPainter painter;
	//���������
	painter.setBrush(d->bkColor);
	//����н���ͻ��Ʊ����ɫ
	if (d->isFocus)
		painter.setBrush(d->hoverColor);
	painter.drawRect(d->x, d->y, d->w, d->h);

	//��������
	if (!m_text.empty())
	{
		painter.drawText(d->x + 10, d->y + (d->h - textheight(m_text.c_str())) / 2, m_text);
	}
	//���ƹ�꣬����˸
	if (d->isFocus)
	{
		static bool isShow = true;
		if (!m_cursorTimer->isStarted())
		{
			m_cursorTimer->start();
		}
		if (m_cursorTimer->elapsed() >= 500)
		{
			isShow = !isShow;
			m_cursorTimer->reStart();
		}
		if (isShow)
		{
			int w = textwidth(m_text.substr(0, m_cursorPos).data());
			painter.drawLine(d->x + 10 + w, d->y + 5, d->x + 10 + w, d->y + d->h - 5);
		}

	}
}

void SLineEdit::charEvent(ExMessage* msg)
{
	printf("charEvent %c ", msg->ch);
	switch (msg->ch)
	{
	case '\b':		//ɾ��
	{
		if (m_cursorPos == m_maxPos)
		{
			//���뻹�������ַ��������������ַ����һ�����ģ���ɾ���������������ÿ���ֽڶ��Ǹ�����
			if (m_maxPos > 1 && m_text[m_maxPos - 1] < 0 && m_text[m_maxPos - 2] < 0)
			{
				m_text.erase(m_maxPos - 2,2);
				m_cursorPos -= 2;
			}
			//ɾ��һ���ַ�
			else if (!m_text.empty())
			{
				m_text.erase(m_maxPos - 1, 1);
				m_cursorPos -= 1;
			}
		}
		else if(!m_text.empty())
		{
			//���뻹�������ַ��������������ַ����һ�����ģ���ɾ���������������ÿ���ֽڶ��Ǹ�����
			if (m_cursorPos <m_maxPos && m_text[m_cursorPos - 1] < 0 && m_text[m_cursorPos - 2] < 0)
			{
				m_text.erase(m_cursorPos - 2,2);
				m_cursorPos -= 2;
			}
			//ɾ��һ���ַ�
			else if (!m_text.empty())
			{
				m_text.erase(m_cursorPos - 1, 1);
				m_cursorPos -= 1;
			}
		}
		break;
	}
	case '\r':
	case '\n':		 //����			
		break;
	default:		//����
		m_text.insert(m_cursorPos, 1, msg->ch);
		m_cursorPos++;
		break;
	}
	m_maxPos = m_text.size();

}

void SLineEdit::keyPressEvent(ExMessage* msg)
{
	if (msg->vkcode == VK_LEFT && m_cursorPos > 0)
	{
		//���뻹�������ַ��������������ַ����һ�����ģ���ɾ���������������ÿ���ֽڶ��Ǹ�����
		if (m_cursorPos > 1 && m_text[m_cursorPos - 1] < 0 && m_text[m_cursorPos - 2] < 0)
		{
			m_cursorPos -= 2;
		}
		//ɾ��һ���ַ�
		else if (!m_text.empty())
		{
			m_cursorPos -= 1;
		}
	}
	else if (msg->vkcode == VK_RIGHT && m_cursorPos < m_maxPos)
	{
		if (m_cursorPos < m_maxPos && m_text[m_cursorPos] < 0 && m_text[m_cursorPos + 1] < 0)
		{
			m_cursorPos += 2;
		}
		else if(m_cursorPos < m_maxPos)
		{
			m_cursorPos += 1;
		}
	}
}


