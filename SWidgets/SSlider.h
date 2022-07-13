#ifndef _SSLIDER_H_
#define _SSLIDER_H_
#include "SAbstractSlider.h"

class SSlider : public SAbstractSlider
{
public:
	SSlider(SWidget* parent = nullptr);
protected:
	void paintEvent(ExMessage* msg)override;
};

#endif