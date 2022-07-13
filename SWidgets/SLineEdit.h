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
	std::string m_text;		//��ʾ���ı�

	int m_maxPos = 0;
	int m_cursorPos = 0;			//��ǰ���λ��
	SElapsedTimer* m_cursorTimer = nullptr;

};

#endif