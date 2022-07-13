#pragma once
#include"../SCore/Configer.h"
#include"../SCore/SRect.h"
#include"../SCore/SColor.h"
class SImage;
class SPainter
{
public:
	SPainter();
	//���û���
	void setPen(const SColor& color,uint32 lineSize = 1);
	//���û�ˢ
	void setBrush(const SColor& color);

	//���Ƶ�
	void drawPoint(int x, int y);
	void drawPoint(const SPoint& pos);
	//������
	void drawLine(int x1, int y1, int x2, int y2);
	void drawLine(const SPoint&p1,const SPoint&p2);
	//���ƾ���
	void drawRect(int x, int y, int w, int h);
	void drawRect(const SPoint& leftTop, const SPoint& rightBottom);
	void drawRect(const SRect& rect);

	//���ƶ���� ������������
	void drawPolygon(const SPoint* points, int num);
	void drawPolygon(const std::vector<SPoint> points);

	//����Բ��
	void drawEllipse(int x, int y, int w, int h);
	void drawEllipse(const SPoint&leftTop, const SPoint& rightBottom);
	void drawEllipse(const SRect&rect);
	void drawCircle(int x, int y, int radius);
	void drawCircle(const SPoint&pos, int radius);

	//�����ı�
	void drawText(int x, int y, const std::string& text);
	void drawText(int x, int y,int w,int h, const std::string& text);
	void drawText(const SRect&rect, const std::string& text);

	//����ͼƬ
	void drawImage(int x, int y, const SImage& image);
	void drawPngImage(int x, int y, const SImage& image);
private:
	SColor m_penColor;		//����
	SColor m_brushColor;	//��ˢ
	uint32 m_lineSize;		//�������
};

