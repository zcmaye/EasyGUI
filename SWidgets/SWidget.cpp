#include"SWidget.h"
#include"SPainter.h"
#include"SWindow.h"
SWidget::SWidget(SWidget* parent)
	:SObject(parent)
	,d(new SWidgetData)
{
	SWindow::getObjectList().push_back(this);
}

SWidget::~SWidget()
{
	delete d;
}

void SWidget::move(int x, int y)
{
	d->x = x;
	d->y = y;
	moveEvent(nullptr);
}

void SWidget::move(const SPoint& pos)
{
	move(pos.getX(), pos.getY());
}

SPoint SWidget::pos() const
{
	return SPoint(d->x,d->y);
}

void SWidget::setFixedSize(int w, int h)
{
	d->w = w;
	d->h = h;
}

void SWidget::setWidth(int w)
{
	d->w = w;
}

void SWidget::setHeight(int h)
{
	d->h = h;
}

SSize SWidget::size() const
{
	return SSize(d->w,d->h);
}

int SWidget::width() const
{
	return d->w;
}

int SWidget::height() const
{
	return d->h;
}

void SWidget::setGeometry(int x, int y, int w, int h)
{
	d->x = x;
	d->y = y;
	d->w = w;
	d->h = h;
	moveEvent(nullptr);
}

void SWidget::setGeometry(const SPoint& pos, const SSize& size)
{
	setGeometry(pos.getX(), pos.getY(), size.getWidth(), size.getHeight());
}

void SWidget::setGeometry(const SRect& rect)
{
	setGeometry(rect.leftTop(), rect.size());
}

SRect SWidget::rect() const
{
	return SRect(0,0,d->w,d->h);
}

SRect SWidget::geometry() const
{
	return SRect(d->x,d->y,d->w,d->h);
}

void SWidget::setBackgroundColor(const SColor& color)
{
	d->bkColor = color;
}

void SWidget::setFrameColor(const SColor& color)
{
	d->frameColor = color;
}

void SWidget::setHoverColor(const SColor& color)
{
	d->hoverColor = color;
}

void SWidget::setTextColor(const SColor& color)
{
	d->textColor = color;
}

void SWidget::setMouseTracking(bool isTracking)
{
	d->isMouseTracking = isTracking;
}

void SWidget::setFocus(bool focus)
{
	d->isFocus = focus;
}



bool SWidget::event(ExMessage* msg)
{

	switch (msg->message)
	{
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:	
		sclog << msg->x <<"," << msg->y << std::endl;
		sclog <<std::boolalpha<< geometry()<< contains(msg->x, msg->y) << std::endl;
		if (contains(msg->x, msg->y))
		{
			mousePressEvent(msg);
			d->isFocus = true;
		}		
		else
		{
			d->isFocus = false;
		}
		break;
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
		//if (contains(msg->x, msg->y))
			mouseReleaseEvent(msg);
		break;
	case WM_MOUSEMOVE:
		if (d->isMouseTracking /*&& contains(msg->x, msg->y)*/)
		{
			mouseMoveEvent(msg);
		}
		if (!d->isHover && contains(msg->x, msg->y))
		{
			enterEvent(msg);
			d->isHover = true;
		}
		else if(d->isHover == true && !contains(msg->x, msg->y))
		{
			leaveEvent(msg);
			d->isHover = false;
		}		
		break;
	case WM_LBUTTONDBLCLK:
		if (contains(msg->x, msg->y))
			mouseDoubleClickEvent(msg);
		break;
	case WM_MOUSEWHEEL:
		if (contains(msg->x, msg->y))
			mouseWheelEvent(msg);
		break;
	case WM_KEYDOWN:
		keyPressEvent(msg);
		break;
	case WM_KEYUP:
		keyReleaseEvent(msg);
		break;
	case WM_CHAR:
		if(d->isFocus)
			charEvent(msg);
	default:
		break;
	}
	paintEvent(msg);
	return false;
}

void SWidget::mousePressEvent(ExMessage* msg)
{
	//slog("mousePressEvent\n");
}

void SWidget::mouseReleaseEvent(ExMessage* msg)
{
	//slog("%s\n", __FUNCTION__);
}

void SWidget::mouseMoveEvent(ExMessage* msg)
{
	//slog("%s\n", __FUNCTION__);
}

void SWidget::mouseWheelEvent(ExMessage* msg)
{
	//slog("%s\n", __FUNCTION__);
}

void SWidget::mouseDoubleClickEvent(ExMessage* msg)
{
	//slog("%s\n", __FUNCTION__);
}

void SWidget::keyPressEvent(ExMessage* msg)
{
	//slog("%s\n", __FUNCTION__);
}

void SWidget::keyReleaseEvent(ExMessage* msg)
{
	//slog("%s\n",__FUNCTION__);
}

void SWidget::paintEvent(ExMessage* msg)
{
	//绘制一个矩形
	SPainter painter;
	painter.setBrush(d->curColor);
	painter.setPen(d->frameColor);
	painter.drawRect(d->x, d->y, d->w, d->h);
}

void SWidget::enterEvent(ExMessage* msg)
{
	//slog("%s\n", __FUNCTION__);
	d->curColor = d->hoverColor;
}

void SWidget::leaveEvent(ExMessage* msg)
{
	//slog("%s\n", __FUNCTION__);
	d->curColor = d->bkColor;
}

void SWidget::charEvent(ExMessage* msg)
{
}

void SWidget::moveEvent(ExMessage* msg)
{
}

bool SWidget::contains(int x, int y)
{
	return geometry().contains(x, y);
}
