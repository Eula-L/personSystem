//��ͨ����
#pragma once
#include<iostream>
#include<fstream>
#include <iomanip>//��ʽ���
using namespace std;
#include"Ordinary.h"
#include"globalFile.h"

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
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.ע����½             |\n";
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
	//�洢��Ϣ
	string name;
	string phone;
	string startLoc;
	int way;//1����2���ͳ�3���ɻ�4������
	string wayID;
	string homeLoc;
	//���ļ�
	ifstream ifs;
	ifs.open(NOTICE, ios::in);//�û��������֤�ţ��绰�ţ�ʼ���أ����з�ʽ�����Σ���ͥסַ
	while (ifs >> name && ifs >> phone && ifs >> startLoc && ifs >> way && ifs >> wayID && ifs >> homeLoc)
	{
		cout << setw(15) << std::left << name << setw(15) << std::left << phone << setw(15) << std::left << startLoc;
		if (way == 1)
		{
			cout << setw(15) << std::left << "��";
		}
		else if (way == 2)
		{
			cout << setw(15) << std::left << "�ͳ�";
		}
		else if (way == 3)
		{
			cout << setw(15) << std::left << "�ɻ�";
		}
		else if (way == 4)
		{
			cout << setw(15) << std::left << "����";
		}
		cout << setw(15) << std::left << wayID << setw(15) << std::left << homeLoc << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}
//�����û�����
void Ordinary::changeType()
{

}
