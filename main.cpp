#include<iostream>
#include"SWidgets/SWindow.h"
#include"SWidgets/SLineEdit.h"
#include"SWidgets/SPushButton.h"
#include"SWidgets/SSlider.h"
#include"SWidgets/SMenuBar.h"
#include"SWidgets/SMenu.h"



int main()
{
	SWindow w(640, 480);
	w.setBackground(RED);

	SMenuBar bar;
	bar.addMenu("�ļ�")->addAction("�½�");
	bar.addMenu("Maye")->addAction("��ʯ");
	bar.addMenu("�ļ�")->addAction("file");
	bar.addMenu("��Ŀ")->addAction("pro");
	bar.addMenu(new SMenu("aaa"));
	//bar.hidden();


	return w.exec();
}