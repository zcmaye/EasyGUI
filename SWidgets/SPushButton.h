#ifndef _SPUSHBUTTON_H_
#define _SPUSHBUTTON_H_
#include "SWidget.h"
using OnClickedFun = void (*)(void*);
class SPushButton : public SWidget
{
public:
	SPushButton(SWidget* parent = nullptr);
	SPushButton(const std::string& text,SWidget* parent = nullptr);
	//设置鼠标点击的回调函数
	void onClicked(OnClickedFun fun,void* data = nullptr);
protected:
	void paintEvent(ExMessage* msg)override;
	void mousePressEvent(ExMessage* msg)override;
private:
	std::string m_text;		//按钮上面显示的文本

	OnClickedFun m_onClickedfun;
	void* m_data;
};

#endif