//��ͨ����
#pragma once
#include<iostream>
using namespace std;
#include"Ordinary.h"

//Ĭ�Ϲ���
Ordinary::Ordinary()
{

}
//�вι���
Ordinary::Ordinary(string name, string pwd)
{

}

//�˵�����
void Ordinary::operMenu()
{
	cout << "��ӭ��ͨ�û���" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.�鿴����             |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�����˻�����         |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.ע����½             |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//��ͨ�û��ӽ���
void Ordinary::ordinaryMenu(Identity*& ordinary)
{
	while (true)
	{
		//��ͨ�û��˵�
		ordinary->operMenu();
		Ordinary* man = (Ordinary*)ordinary;

		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "�鿴����" << endl;
			man->showNotice();
		}
		else if (select == 2)
		{
			cout << "�����˻�����" << endl;
			man->changeType();
		}
		else
		{
			delete man;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
//�鿴����
void Ordinary::showNotice()
{

}
//�����û�����
void Ordinary::changeType()
{

}
