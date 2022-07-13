#ifndef _SWINDOW_H_
#define _SWINDOW_H_
#include"../SCore/Configer.h"
#include"../SCore/SColor.h"
#include"../SCore/SObject.h"
class SWindow
{
public:
	SWindow(int w,int h,int flag = EW_SHOWCONSOLE);
	~SWindow();
	//设置窗口标题
	void setWindowTile(const std::string& title);
	void setBackground(const SColor& color);


	//消息循环
	int exec();
	virtual void loop(ExMessage*msg);

	inline static SObjectList& getObjectList() { return s_objectList; };
private:
	HWND _hwnd;
	static SObjectList s_objectList;
};

#endif