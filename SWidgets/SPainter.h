#pragma once
#include"../SCore/Configer.h"
#include"../SCore/SRect.h"
#include"../SCore/SColor.h"
class SImage;
class SPainter
{
public:
	SPainter();
	//设置画笔
	void setPen(const SColor& color,uint32 lineSize = 1);
	//设置画刷
	void setBrush(const SColor& color);

	//绘制点
	void drawPoint(int x, int y);
	void drawPoint(const SPoint& pos);
	//绘制线
	void drawLine(int x1, int y1, int x2, int y2);
	void drawLine(const SPoint&p1,const SPoint&p2);
	//绘制矩形
	void drawRect(int x, int y, int w, int h);
	void drawRect(const SPoint& leftTop, const SPoint& rightBottom);
	void drawRect(const SRect& rect);

	//绘制多边形 点的数组和数量
	void drawPolygon(const SPoint* points, int num);
	void drawPolygon(const std::vector<SPoint> points);

	//绘制圆形
	void drawEllipse(int x, int y, int w, int h);
	void drawEllipse(const SPoint&leftTop, const SPoint& rightBottom);
	void drawEllipse(const SRect&rect);
	void drawCircle(int x, int y, int radius);
	void drawCircle(const SPoint&pos, int radius);

	//绘制文本
	void drawText(int x, int y, const std::string& text);
	void drawText(int x, int y,int w,int h, const std::string& text);
	void drawText(const SRect&rect, const std::string& text);

	//绘制图片
	void drawImage(int x, int y, const SImage& image);
	void drawPngImage(int x, int y, const SImage& image);
private:
	SColor m_penColor;		//画笔
	SColor m_brushColor;	//画刷
	uint32 m_lineSize;		//线条宽度
};

