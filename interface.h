//��������
#pragma once
#include<iostream>
#include <stdio.h>
#include <windows.h>
//�ı�ȫ�ִ��ڱ���ɫ��ǰ��ɫ
void setAllColor(unsigned short backColor = 0, unsigned short textColor = 7) {
	char command[9] = "color 07";		//Ĭ����ɫ	
	command[6] = '0' + backColor;		//��backColor������Ϊ�ַ��� 
	command[7] = '0' + textColor;		//��textColor������Ϊ�ַ��� 
	system(command);				//����ϵͳ���� 
}
