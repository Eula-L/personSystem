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
	cout << "��ӭ��ͨ�û�" << "��¼��" << endl;
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
	MyStruct my;
	ifstream ifs;
	ifs.open(NOTICE, ios::in);//�û��������֤�ţ��绰�ţ�ʼ���أ����з�ʽ�����Σ���ͥסַ
	while (ifs >> my.name && ifs >> my.phone && ifs >> my.startLoc && ifs >> my.way && ifs >> my.wayID && ifs >> my.homeLoc)
	{
		cout << setw(15) << std::left << my.name << setw(15) << std::left << my.phone << setw(15) << std::left << my.startLoc;
		if (my.way == 1)
		{
			cout << setw(15) << std::left << "��";
		}
		else if (my.way == 2)
		{
			cout << setw(15) << std::left << "�ͳ�";
		}
		else if (my.way == 3)
		{
			cout << setw(15) << std::left << "�ɻ�";
		}
		else if (my.way == 4)
		{
			cout << setw(15) << std::left << "����";
		}
		cout << setw(15) << std::left << my.wayID << setw(15) << std::left << my.homeLoc << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}
