#include"SMenu.h"
#include"SPainter.h"
#include"SAction.h"
SMenu::SMenu(SWidget* parent)
	:SMenu("Menu", parent)
{
	setFixedSize(60, 20);
}

SMenu::SMenu(const std::string& title, SWidget* parent)
	:SWidget(parent)
{
	setWindowTitle(title);
}

SAction* SMenu::addAction(const std::string& text)
{
	auto act = new SAction(text, this);
	return addAction(act);
}

SAction* SMenu::addAction(SAction* act)
{
	m_actions.push_back(act);
	return act;
}

std::string SMenu::title() const
{
	return windowTitle();
}

void SMenu::popUp(int x, int y)
{
	move(x, y);
}

void SMenu::popUp(const SPoint& pos)
{
	move(pos);
}

void SMenu::paintEvent(ExMessage* msg)
{
	SPainter painter;
	for (int i = 0; i < m_actions.size(); i++)
	{
		m_actions[i]->move(d->x, i * m_actions.front()->height());
	}
	
	SWidget::paintEvent(msg);
}
