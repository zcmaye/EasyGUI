#ifndef _SIMAGE_H_
#define _SIMAGE_H_
#include "Configer.h"
class SImage :public IMAGE
{
public:
	SImage(int w = 0, int h = 0);
	SImage(const std::string& filename,int w = 0,int h = 0);
	void load(const std::string& filename, int w = 0, int h = 0);
private:
	void SetDefault()override {}

};


#endif