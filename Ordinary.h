//��ͨ����
/*��Ҫ���ܣ�
*	ע���˺�
*	��¼
*	�鿴����
*/
#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"

//��ͨ����
class Ordinary :public Identity
{
public:
	//Ĭ�Ϲ���
	Ordinary();
	//�вι���
	Ordinary(string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//ע��
	void addPerson();
	//�鿴����
	void showNotice();
};