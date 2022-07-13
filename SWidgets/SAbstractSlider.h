#ifndef _SABSTRACTSLIDER_H_
#define _SABSTRACTSLIDER_H_
#include "SWidget.h"

class SAbstractSlider : public SWidget
{
public:
	SAbstractSlider(SWidget* parent = nullptr);

	void setOrientation(EasyGUI::Orientation);
	EasyGUI::Orientation orientation() const;

	void setRange(int min, int max);
	void setValue(int val);
	void setMaximum(int max);
	void setMinimum(int min);
	int maximum() const;
	int minimum() const;

protected:
	void paintEvent(ExMessage* msg) override;
	void mousePressEvent(ExMessage* msg)override;
	void mouseReleaseEvent(ExMessage* msg)override;
	void mouseMoveEvent(ExMessage* msg)override;
	void moveEvent(ExMessage* msg)override;

	SRect m_handleRect;	//手柄矩形区域
private:
	bool m_isPressHandle = false;	//是否按下了手柄
	EasyGUI::Orientation m_orientation;
	int m_max = 100;	
	int m_min = 0;		//最小值
	int m_value = 0;	//当前值
	int m_step = 1;		//步长
	int m_distance = 0;		//滑块距离左边/上边的距离
};

#endif