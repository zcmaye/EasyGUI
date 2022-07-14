#ifndef _SMENUBAR_H_
#define _SMENUBAR_H_
#include"SWidget.h"	
#include<map>
class SMenu;
class SAction;
class SMenuBar:public SWidget
{
public:
	SMenuBar(SWidget* parent = nullptr);
	SAction* addMenu(SMenu* menu);
	SMenu* addMenu(const std::string& title);
protected:
	void paintEvent(ExMessage* msg)override;
	void mousePressEvent(ExMessage* msg)override;
private:
	std::multimap<SAction*, SMenu*> m_actMenuMap;
};
#endif