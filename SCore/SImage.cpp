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
	//�ж�ͼƬ�Ƿ���سɹ�
	if (this->getwidth() == 0 || this->getheight() == 0)
	{
		sclog<<"SImage load failed\n";
	}
}
