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

	SRect m_handleRect;	//�ֱ���������
private:
	bool m_isPressHandle = false;	//�Ƿ������ֱ�
	EasyGUI::Orientation m_orientation;
	int m_max = 100;	
	int m_min = 0;		//��Сֵ
	int m_value = 0;	//��ǰֵ
	int m_step = 1;		//����
	int m_distance = 0;		//����������/�ϱߵľ���
};

#endif