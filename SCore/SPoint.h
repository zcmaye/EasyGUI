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
	int x()const;
	int y()const;
	friend std::ostream& operator<<(std::ostream& out, const SPoint& pos);

	//判断一下点是否是空的
	bool isNull();
private:
	int m_x;
	int m_y;
};

#endif