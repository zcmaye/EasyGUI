#ifndef _SWIDGET_H_
#define _SWIDGET_H_
#include"../SCore/Configer.h"
#include"../SCore/SObject.h"
#include"../SCore/SColor.h"
#include"../SCore/SGeometry.h"
struct SWidgetData
{
	SWidgetData()
	{
		isMouseTracking = false;
		isFocus = false;
		isHover = false;
		bkColor = hoverColor = curColor = SColor(230, 231, 232);
		textColor = SColor::Black;
		frameColor = SColor::Black;
	}
	int16 x = 0;
	int16 y = 0;
	int16 w = 250;
	int16 h = 250;
	SColor bkColor;			//背景颜色
	SColor frameColor;		//边框颜色
	SColor hoverColor;		//鼠标悬停颜色
	SColor textColor;		//文本颜色
	SColor curColor;		//当前颜色

	uint8 isMouseTracking : 1;		//是否开启鼠标追踪
	uint8 isHover:1;			    //鼠标是否悬停
	uint8 isFocus:1;				//控件是否有焦点
};

class SWidget :public SObject
{
public:
	SWidget(SWidget* parent = nullptr);
	~SWidget();
	//禁止拷贝禁止移动
	SWidget(const SWidget&) = delete;
	SWidget(SWidget&&) = delete;

	//移动控件
	void move(int x, int y);
	void move(const SPoint&pos);
	SPoint pos() const;

	//设置尺寸
	void setFixedSize(int w, int h);
	void setWidth(int w);
	void setHeight(int h);
	SSize size()const;
	int width()const;
	int height()const;

	//设置几何大小
	void setGeometry(int x, int y, int w, int h);
	void setGeometry(const SPoint& pos, const SSize& size);
	void setGeometry(const SRect&rect);
	SRect rect()const;			//SRect(0,0,d->w,d->h)
	SRect geometry()const;		//SRect(d->x,d->y,d->w,d->h)
	


	//设置背景和边框颜色
	void setBackgroundColor(const SColor& color);
	void setFrameColor(const SColor& color);
	void setHoverColor(const SColor& color);
	void setTextColor(const SColor& color);
	//设置鼠标追踪
	void setMouseTracking(bool isTracking);
	void setFocus(bool focus);
protected:
	bool event(ExMessage* msg)override;
	virtual void mousePressEvent(ExMessage* msg);
	virtual void mouseReleaseEvent(ExMessage* msg);
	virtual void mouseMoveEvent(ExMessage* msg);
	virtual void mouseWheelEvent(ExMessage* msg);
	virtual void mouseDoubleClickEvent(ExMessage* msg);
	virtual void keyPressEvent(ExMessage* msg);
	virtual void keyReleaseEvent(ExMessage* msg);
	virtual void paintEvent(ExMessage* msg);
	virtual void enterEvent(ExMessage* msg);
	virtual void leaveEvent(ExMessage* msg);
	virtual void charEvent(ExMessage* msg);
	virtual void moveEvent(ExMessage* msg);

	SWidgetData* d;
private:
	bool contains(int x, int y);	//判断控件是否包含鼠标的坐标
};

#endif