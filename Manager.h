//����Ա��
/*
* �鿴����
* ���������˺�
* �����Ϣ
* ���������¹���
*/
#pragma once
#include<iostream>
#include<vector>
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
	//����Ա�ӽ���
	void managerMenu(Identity*& manager);
	//�鿴�˺�
	void showPerson();
	//�鿴��ǰ�ϱ���Ϣ
	void showInfo();
	//���¹���
	void changeNotice();
	//��չ���
	void cleanNotice();
	//�鿴����
	void showNotice();


};