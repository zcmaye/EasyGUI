#ifndef _SMENU_H_
#define _SMENU_H_
#include "SWidget.h"
class SAction;
class SMenu : public SWidget
{
public:
	SMenu(SWidget* parent = nullptr);
	SMenu(const std::string& title, SWidget* parent = nullptr);
	SAction* addAction(const  std::string& text);
	SAction* addAction(SAction*act);
	std::string title()const;
	void popUp(int x, int y);
	void popUp(const SPoint&pos);
protected:
	void paintEvent(ExMessage* msg)override;
private:
	std::vector<SAction*> m_actions;
};

#endif