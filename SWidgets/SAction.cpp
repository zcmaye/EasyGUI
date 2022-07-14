#include"SAction.h"
#include"SPainter.h"
SAction::SAction(SWidget* parent)
	:SAction("action",parent)
{
	
}

SAction::SAction(const std::string& text, SWidget* parent)
	:SPushButton(text,parent)
{
	this->setWindowTitle(text);
	setFixedSize(60, 20);
}

bool SAction::event(ExMessage* msg)
{
	return SPushButton::event(msg);
}
