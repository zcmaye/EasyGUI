#ifndef _SPOINT_H_
#define _SPOINT_H_
#include"Configer.h"
class SPoint
{
public:
	SPoint();
	SPoint(int x, int y);

	void setX(int x);
	void setY(int y);
	int getX()const;
	int getY()const;

	//�ж�һ�µ��Ƿ��ǿյ�
	bool isNull();
private:
	int m_x;
	int m_y;
};

#endif