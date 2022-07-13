#include<iostream>
#include"SWidgets/SWindow.h"
#include"SWidgets/SLineEdit.h"
#include"SWidgets/SPushButton.h"
#include"SWidgets/SSlider.h"



int main()
{
	SWindow w(640, 480);
	w.setBackground(RED);

	//SLineEdit edit;
	////edit.setFocus(true);
	//edit.setHoverColor(SColor(252, 252, 252));
	//edit.setFixedSize(200, 40);

	SPushButton btn;
	btn.onClicked([](void*) {slog("hello world\n"); }, nullptr);

	SAbstractSlider slider;
	slider.move(100, 50);
	slider.setOrientation(EasyGUI::Vertical);
	slider.setOrientation(EasyGUI::Horizontal);
	slider.setRange(0, 100);

	return w.exec();
}