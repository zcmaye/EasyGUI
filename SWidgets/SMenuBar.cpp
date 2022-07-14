#include"SMenuBar.h"
#include"SPushButton.h"
#include"SMenu.h"
#include"SPainter.h"
#include"../SCore/Configer.h"
#include"SAction.h"
SMenuBar::SMenuBar(SWidget* parent)
{
	
}

SAction* SMenuBar::addMenu(SMenu* menu)
{
	auto btn = new SAction(menu->title(), menu);
	m_actMenuMap.insert({ btn, menu });
	return btn;
}

SMenu* SMenuBar::addMenu(const std::string& title)
{
	SMenu* menu = new SMenu(title);
	auto act = addMenu(menu);
	//¼ÆËãMmenuBarµÄ¿í¶È
	d->w = m_actMenuMap.size() * m_actMenuMap.begin()->first->width();
	d->h = m_actMenuMap.begin()->first->height();
	return menu;
}

void SMenuBar::paintEvent(ExMessage* msg)
{
	SPainter painter;
	int i = 0;
	for (auto val : m_actMenuMap)
	{
		val.first->move(i * val.first->width(), 0);
		i++;
	}
}

void SMenuBar::mousePressEvent(ExMessage* msg)
{
	int no = msg->x / m_actMenuMap.begin()->first->width();
	int i = 0;
	for (auto val : m_actMenuMap)
	{
		if (no == i)
		{
			val.second->popUp(msg->x,msg->y+50);
		}
		i++;
	}
}
