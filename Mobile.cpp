//������Ա��
#include<iostream>
using namespace std;
#include"Mobile.h"

//Ĭ�Ϲ���
Mobile::Mobile()
{

}
//�вι��죨�������û��������룬���֤�ţ��绰�ţ�ʼ���أ����з�ʽ�����Σ���ͥסַ��
Mobile::Mobile(string name, string pwd)
{

}

//�˵�����
void Mobile::operMenu()
{
	cout << "��ӭ������Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.���Ϣ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}
//������Ա�ӽ���
void Mobile::mobileMenu(Identity*& mobile)
{
	while (true)
	{
		//����Ա�˵�
		mobile->operMenu();
		Mobile* man = (Mobile*)mobile;

		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "�鿴����" << endl;
			man->showNotice();
		}
		else if (select == 2)
		{
			cout << "���Ϣ" << endl;
			man->addInfo();
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
void Mobile::showNotice()
{

}

//���Ϣ
void Mobile::addInfo()
{

}