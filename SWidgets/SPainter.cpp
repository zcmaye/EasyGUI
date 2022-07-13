#include "SPainter.h"

SPainter::SPainter()
	:m_penColor(BLACK)
	,m_brushColor(RGB(194, 195, 201))
	,m_lineSize(1)
{
}

void SPainter::setPen(const SColor& color, uint32 lineSize)
{
	m_penColor = color;
	m_lineSize = lineSize;
}

void SPainter::setBrush(const SColor& color)
{
	m_brushColor = color;
}

void SPainter::drawPoint(int x, int y)
{
	putpixel(x, y, m_penColor);
}

void SPainter::drawPoint(const SPoint& pos)
{
	drawPoint(pos.getX(), pos.getY());
}

void SPainter::drawLine(int x1, int y1, int x2, int y2)
{
	setlinecolor(m_penColor);
	setlinestyle(PS_SOLID, m_lineSize);
	line(x1, y1, x2, y2);
}

void SPainter::drawLine(const SPoint& p1, const SPoint& p2)
{
	drawLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
}

void SPainter::drawRect(int x, int y, int w, int h)
{
	setfillcolor(m_brushColor);
	setlinecolor(m_penColor);
	fillrectangle(x, y, x + w, y + h);
}

void SPainter::drawRect(const SPoint& leftTop, const SPoint& rightBottom)
{
	drawRect(leftTop.getX(), leftTop.getY(), rightBottom.getX(), rightBottom.getY());
}

void SPainter::drawRect(const SRect& rect)
{
	drawRect(rect.leftTop(), rect.rightBottom());
}

void SPainter::drawPolygon(const SPoint* points, int num)
{
	setfillcolor(m_brushColor);
	setlinecolor(m_penColor);
	fillpolygon((POINT*)points, num);
}

void SPainter::drawPolygon(const std::vector<SPoint> points)
{
	drawPolygon(points.data(), points.size());
}

void SPainter::drawEllipse(int x, int y, int w, int h)
{
	setfillcolor(m_brushColor);
	setlinecolor(m_penColor);
	fillellipse(x, y, x + w, y + h);
}

void SPainter::drawEllipse(const SPoint& leftTop, const SPoint& rightBottom)
{
	drawEllipse(leftTop.getX(), leftTop.getY(), rightBottom.getX() - leftTop.getX(), rightBottom.getY() - leftTop.getY());
}

void SPainter::drawEllipse(const SRect& rect)
{
	drawEllipse(rect.leftTop(), rect.rightBottom());
}

void SPainter::drawCircle(int x, int y, int radius)
{
	drawEllipse(x - radius, y - radius, radius * 2, radius * 2);
}

void SPainter::drawCircle(const SPoint& pos, int radius)
{
	drawCircle(pos.getX(), pos.getY(), radius);
}

void SPainter::drawText(int x, int y, const std::string& text)
{
	settextcolor(m_penColor);
	outtextxy(x, y, text.c_str());
}

void SPainter::drawText(int x, int y, int w, int h, const std::string& text)
{
	int spaceh = (w - textwidth(text.c_str()))/2;
	int spacev = (h - textheight(text.c_str()))/2;
	drawText(x + spaceh, y + spacev, text);
}

void SPainter::drawText(const SRect& rect, const std::string& text)
{
	drawText(rect.leftTop().getX(), rect.leftTop().getY(), rect.width(), rect.height(), text);
}

void SPainter::drawImage(int x, int y, const SImage& image)
{
	putimage(x, y, (IMAGE*) &image);
}
void drawImg(int x, int y, IMAGE* src);
void SPainter::drawPngImage(int x, int y, const SImage& image)
{
	drawImg(x, y, (IMAGE*)&image);
}

void drawImg(int x, int y, IMAGE* src)
{
	// ������ʼ��
	DWORD* pwin = GetImageBuffer();			//���ڻ�����ָ��
	DWORD* psrc = GetImageBuffer(src);		//ͼƬ������ָ��
	int win_w = getwidth();				//���ڿ��
	int win_h = getheight();
	int src_w = src->getwidth();				//ͼƬ���
	int src_h = src->getheight();

	// ������ͼ��ʵ�ʳ���
	int real_w = (x + src_w > win_w) ? win_w - x : src_w;			// �������ұ߽�
	int real_h = (y + src_h > win_h) ? win_h - y : src_h;			// �������±߽�
	if (x < 0) { psrc += -x;			real_w -= -x;	x = 0; }	// ��������߽�
	if (y < 0) { psrc += (src_w * -y);	real_h -= -y;	y = 0; }	// �������ϱ߽�


	// ������ͼ��ʼλ��
	pwin += (win_w * y + x);

	// ʵ��͸����ͼ
	for (int iy = 0; iy < real_h; iy++)
	{
		for (int ix = 0; ix < real_w; ix++)
		{
			byte a = (byte)(psrc[ix] >> 24);//����͸��ͨ����ֵ[0,256) 0Ϊ��ȫ͸�� 255Ϊ��ȫ��͸��
			if (a > 100)
			{
				pwin[ix] = psrc[ix];
			}
		}
		//������һ��
		pwin += win_w;
		psrc += src_w;
	}
}