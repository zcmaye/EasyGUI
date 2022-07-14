#ifndef _SSIZE_H_
#define _SSIZE_H_

class SSize
{
public:
	SSize();
	SSize(int w, int h);

	void setWidth(int w);
	void setheight(int h);
	int width()const;
	int height()const;

	//判断一下点是否是空的
	bool isNull();
private:
	int m_w;
	int m_h;
};

#endif