//界面美化
#pragma once
#include<iostream>
#include <stdio.h>
#include <windows.h>
//改变全局窗口背景色和前景色
void setAllColor(unsigned short backColor = 0, unsigned short textColor = 7) {
	char command[9] = "color 07";		//默认颜色	
	command[6] = '0' + backColor;		//将backColor变量改为字符型 
	command[7] = '0' + textColor;		//将textColor变量改为字符型 
	system(command);				//调用系统函数 
}
