//�������ݻ���
#pragma once
#include<iostream>
#include<string>
using namespace std;

//��ݳ�����
class Identity
{
public:
	//�����˵�
	virtual void operMenu()=0;
	string m_Name;//�û���
	string m_Pwd;//����
	int val =0;//1����ͨ�û�2��������Ա3������Ա
};