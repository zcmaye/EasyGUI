#ifndef _SPUSHBUTTON_H_
#define _SPUSHBUTTON_H_
#include "SWidget.h"
using OnClickedFun = void (*)(void*);
class SPushButton : public SWidget
{
public:
	SPushButton(SWidget* parent = nullptr);
	SPushButton(const std::string& text,SWidget* parent = nullptr);
	//����������Ļص�����
	void onClicked(OnClickedFun fun,void* data = nullptr);
protected:
	void paintEvent(ExMessage* msg)override;
	void mousePressEvent(ExMessage* msg)override;
private:
	std::string m_text;		//��ť������ʾ���ı�

	OnClickedFun m_onClickedfun;
	void* m_data;
};

#endif