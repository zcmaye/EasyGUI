#ifndef _SSIZE_H_
#define _SSIZE_H_

class SSize
{
public:
	SSize();
	SSize(int w, int h);

	void setWidth(int w);
	void setheight(int h);
	int getWidth()const;
	int getHeight()const;

	//�ж�һ�µ��Ƿ��ǿյ�
	bool isNull();
private:
	int m_w;
	int m_h;
};

#endif