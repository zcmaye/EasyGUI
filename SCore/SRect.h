#ifndef _SRECT_H_
#define _SRECT_H_
#include"SPoint.h"
#include"SSize.h"
class SRect
{
public:
	SRect();
	SRect(int x, int y,int w,int h);
	SRect(const SPoint& leftTop, const SPoint& rightBottom);
	SRect(const SPoint& leftTop, const SSize& size);

	SPoint leftTop()const;
	SPoint leftBottom()const;
	SPoint rightTop()const;
	SPoint rightBottom()const;
	SPoint center()const;
	SSize size()const;
	int width()const;
	int height()const;
	inline int x() { return m_x; };
	inline int y() { return m_y; };

	void setLeft(int x);
	void setTop(int y);
	void setX(int x);
	void setY(int y);
	void setLeftTop(const SPoint& pos);
	void setLeftBottom(const SPoint& pos);
	void moveCenter(const SPoint& position);
	void translate(int dx, int dy);

	//判断某个点是否再矩形内
	bool contains(const SPoint& pos);
	bool contains(int x,int y);

	friend std::ostream& operator<<(std::ostream& out, const SRect& rect);
private:
	int m_x;
	int m_y;
	int m_w;
	int m_h;
};

#endif
