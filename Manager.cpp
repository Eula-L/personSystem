//������Ա��
#include<iostream>
#include <fstream>
using namespace std;
#include "Identity.h"
#include "globalFile.h"
#include "Ordinary.h"
#include "Mobile.h"
#include "Manager.h"
//Ĭ�Ϲ���
Manager::Manager()
{

}
//�вι���
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	
}

//ѡ��˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�����Ϣ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���¹���            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          5.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
//����Ա�ӽ���
void Manager::managerMenu(Identity*& manager)
{
	while (true)
	{
		//����Ա�˵�
		manager->operMenu();
		Manager* man = (Manager*)manager;

		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 2)
		{
			cout << "�����Ϣ" << endl;
			man->showInfo();
		}
		else if (select == 3)
		{
			cout << "�鿴����" << endl;
			man->showNotice();
		}
		else if (select == 4)
		{
			cout << "���¹���" << endl;
			man->changeNotice();
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

//�����˺�
//�鿴�˺�
void Manager::showPerson()
{

}

//�鿴��ǰ�ϱ���Ϣ
void Manager::showInfo()
{

}
//�鿴����
void Manager::showNotice()
{

}
//���¹���
void Manager::changeNotice()
{

}
