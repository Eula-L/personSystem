//����Ա��
/*
* �鿴����
* ���������˺�
* �����Ϣ
* ���������¹���
*/
#pragma once
#include<iostream>
#include <iomanip>//���뻯���
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
	//�����������ģ��
	template<typename T>
	void print(const T& t)
	{
		cout << setw(15) << std::left << t ;
	}
};