#ifndef _SACTION_H_
#define _SACTION_H_
#include "SPushButton.h"

class SAction : public SPushButton
{
public:
	SAction(SWidget* parent = nullptr);
	SAction(const std::string& text, SWidget* parent = nullptr);
	inline std::string text() { return d->title; };
protected:
	bool event(ExMessage* msg)override;
private:
};

#endif