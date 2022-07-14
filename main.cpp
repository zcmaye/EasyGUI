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
	bar.addMenu("文件")->addAction("新建");
	bar.addMenu("Maye")->addAction("顽石");
	bar.addMenu("文件")->addAction("file");
	bar.addMenu("项目")->addAction("pro");
	bar.addMenu(new SMenu("aaa"));
	//bar.hidden();


	return w.exec();
}