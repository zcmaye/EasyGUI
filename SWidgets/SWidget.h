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
	SColor bkColor;			//������ɫ
	SColor frameColor;		//�߿���ɫ
	SColor hoverColor;		//�����ͣ��ɫ
	SColor textColor;		//�ı���ɫ
	SColor curColor;		//��ǰ��ɫ

	uint8 isMouseTracking : 1;		//�Ƿ������׷��
	uint8 isHover:1;			    //����Ƿ���ͣ
	uint8 isFocus:1;				//�ؼ��Ƿ��н���
};

class SWidget :public SObject
{
public:
	SWidget(SWidget* parent = nullptr);
	~SWidget();
	//��ֹ������ֹ�ƶ�
	SWidget(const SWidget&) = delete;
	SWidget(SWidget&&) = delete;

	//�ƶ��ؼ�
	void move(int x, int y);
	void move(const SPoint&pos);
	SPoint pos() const;

	//���óߴ�
	void setFixedSize(int w, int h);
	void setWidth(int w);
	void setHeight(int h);
	SSize size()const;
	int width()const;
	int height()const;

	//���ü��δ�С
	void setGeometry(int x, int y, int w, int h);
	void setGeometry(const SPoint& pos, const SSize& size);
	void setGeometry(const SRect&rect);
	SRect rect()const;			//SRect(0,0,d->w,d->h)
	SRect geometry()const;		//SRect(d->x,d->y,d->w,d->h)
	


	//���ñ����ͱ߿���ɫ
	void setBackgroundColor(const SColor& color);
	void setFrameColor(const SColor& color);
	void setHoverColor(const SColor& color);
	void setTextColor(const SColor& color);
	//�������׷��
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
	bool contains(int x, int y);	//�жϿؼ��Ƿ������������
};

#endif