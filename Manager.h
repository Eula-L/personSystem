//����Ա��
/*
* �鿴����
* ���������˺�
* �����Ϣ
* ���������¹���
*/
#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"

class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string pwd);

	//ѡ��˵�
	virtual void operMenu();

	//ע��
	void addPerson();

	//�����˺�
	//�鿴�˺�
	void showPerson();

	//�鿴��ǰ�ϱ���Ϣ
	void showInfo();
	//���¹���
	void changeNotice();
	//�鿴����
	void showNotice();


};