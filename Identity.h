//�������ݻ���
#pragma once
#include<iostream>
#include<string>
using namespace std;
struct MyStruct
{
	string name;
	string ID;
	string phone;
	string startLoc;
	int way = 0;//1����2���ͳ�3���ɻ�4������
	string wayID;
	string homeLoc;
};

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