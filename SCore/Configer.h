#ifndef _CONFIGER_H_
#define _CONFIGER_H_

//取消UNICODE字符集
#ifdef  UNICODE
#undef UNICODE
#endif //  UNICODE

#include<easyx.h>
#include<string>
#include<vector>
#include<iostream>


using uint8 = unsigned char;
using uint16 = unsigned short;
using uint32 = unsigned int;

using int8  =  char;
using int16 =  short;
using int32 =  int;

#define slog printf
#define sclog std::cout<<"[info:"<<__LINE__<<"] "

namespace EasyGUI
{
	//朝向
	enum Orientation
	{
		Horizontal = 0x1,
		Vertical = 0x2
	};
}

#endif