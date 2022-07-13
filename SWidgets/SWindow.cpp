#include "SWindow.h"
SObjectList SWindow::s_objectList;
SWindow::SWindow(int w, int h, int flag)
{
	_hwnd = initgraph(w, h, flag);
	setbkmode(TRANSPARENT);
}

SWindow::~SWindow()
{
	system("pause");
	closegraph();
}

void SWindow::setWindowTile(const std::string& title)
{
	SetWindowText(_hwnd, title.c_str());
}

void SWindow::setBackground(const SColor& color)
{
	setbkcolor(color);
	cleardevice();
}

int SWindow::exec()
{
	bool isDone = false;
	while (!isDone)
	{
		ExMessage msg = { 0 };
		do
		{
			//按ESC键退出程序
			if (msg.message == WM_KEYDOWN && msg.vkcode == VK_ESCAPE)
			{
				isDone = true;
			}
			BeginBatchDraw();
			cleardevice();
			//所有SWidget的消息循环
			for (auto w : getObjectList())
			{
				w->event(&msg);
			}
			loop(&msg);
			EndBatchDraw();
		} while (peekmessage(&msg));
	}
	return 0;
}

void SWindow::loop(ExMessage* msg)
{
}

