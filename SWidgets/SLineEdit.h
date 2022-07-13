#ifndef _SLINEEDIT_H_
#define _SLINEEDIT_H_
#include "SWidget.h"
class  SElapsedTimer;
class SLineEdit :public SWidget
{
public:
	SLineEdit(SWidget*parent = nullptr);
	~SLineEdit();

protected:
	void paintEvent(ExMessage* msg)override;
	void charEvent(ExMessage* msg)override;
	void keyPressEvent(ExMessage* msg)override;
private:
	std::string m_text;		//显示的文本

	int m_maxPos = 0;
	int m_cursorPos = 0;			//当前光标位置
	SElapsedTimer* m_cursorTimer = nullptr;

};

#endif