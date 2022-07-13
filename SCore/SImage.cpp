#include"SImage.h"
#include<iostream>
using namespace std;
SImage::SImage(int w, int h)
	:IMAGE(w,h)
{
}

SImage::SImage(const std::string& filename,int w,int h)
{
	load(filename, w, h);
}

void SImage::load(const std::string& filename, int w, int h)
{
	loadimage(this, filename.c_str(), w, h);
	//判断图片是否加载成功
	if (this->getwidth() == 0 || this->getheight() == 0)
	{
		sclog<<"SImage load failed\n";
	}
}
