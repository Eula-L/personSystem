//������Ա��
#include<iostream>
#include <fstream>
#include <iomanip>//��ʽ���
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
	

	string fName;
	string fPwd;
	int sta = 0;//txt�е����б�ʾ��ݣ�1����ͨ��2��������Ա3������Ա
	for (int i = 3; i > 0; i--)
	{
		cout << i << endl;
		if (i == 3)
		{
			
			cout << "����Ա�˺���Ϣ" << endl;
		}
		else if (i == 2)
		{
			cout << "������Ա�˺���Ϣ" << endl;
		}
		else 
		{
			cout << "��ͨ�û��˺���Ϣ" << endl;
		}
		//���ļ�
		ifstream ifs;
		ifs.open(PEOPLE, ios::in);//���ַ����������ļ�ֻ�����һ��
		while (ifs >> fName && ifs >> fPwd && ifs >> sta)
		{
			if (sta == i)
			{
				//Ӧ����һ���������
				cout << fName << "   " << fPwd << endl;
			}
		}
		cout << endl;
	}
	system("pause");
	system("cls");
	return;
}

//�鿴��ǰ�ϱ���Ϣ
void Manager::showInfo()
{
	//�洢��Ϣ
	string name;
	string ID;
	string phone;
	string startLoc;
	int way=0;//1����2���ͳ�3���ɻ�4������
	string wayID;
	string homeLoc;
	cout << setw(15) << std::left << "����" << setw(15) << std::left << "���֤��" << setw(15) << std::left << "�绰��" << setw(15) << std::left << "ʼ����"<<setw(15) << std::left <<"���з�ʽ"<<setw(15) << std::left <<"����"<<setw(15) << std::left << "��ͥסַ"<<endl;
	//���ļ�
	ifstream ifs;
	ifs.open(INFOMATION, ios::in);//�û��������֤�ţ��绰�ţ�ʼ���أ����з�ʽ�����Σ���ͥסַ
	while (ifs >> name && ifs >> ID && ifs >> phone && ifs >> startLoc && ifs >> way && ifs >> wayID && ifs >> homeLoc)
	{
		
		cout << setw(15) << std::left << name << setw(15) << std::left << ID << setw(15) << std::left << phone << setw(15) << std::left << startLoc;
		if (way == 1)
		{
			cout<< setw(15) << std::left << "��";
		}
		else if(way==2)
		{
			cout<< setw(15) << std::left << "�ͳ�";
		}
		else if(way==3)
		{
			cout << setw(15) << std::left << "�ɻ�";
		}
		else if(way==4)
		{
			cout << setw(15) << std::left << "����";
		}
		cout << setw(15) << std::left << wayID << setw(15) << std::left << homeLoc << endl;
	}
	system("pause");
	system("cls");
}
//�鿴����
void Manager::showNotice()
{
	//�洢��Ϣ
	string name;
	string phone;
	string startLoc;
	int way;//1����2���ͳ�3���ɻ�4������
	int wayID;
	string homeLoc;
	//���ļ�
	ifstream ifs;
	ifs.open(NOTICE, ios::in);//�û��������֤�ţ��绰�ţ�ʼ���أ����з�ʽ�����Σ���ͥסַ
	while (ifs >> name  && ifs >> phone && ifs >> startLoc && ifs >> way && ifs >> wayID && ifs >> homeLoc)
	{
		cout << setw(15) << std::left << name  << setw(15) << std::left << phone << setw(15) << std::left << startLoc;
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
	system("pause");
	system("cls");
}
//���¹���
void Manager::changeNotice()
{
	//���˺���Ϣ�ļ���д���µ��û���Ϣ
	int n;
	string name1;
	string name;
	string ID;
	string phone;
	string startLoc;
	int way = 0;//1����2���ͳ�3���ɻ�4������
	string wayID;
	string homeLoc;
	ifstream ifs;
	ifs.open(INFOMATION, ios::in);//�û��������֤�ţ��绰�ţ�ʼ���أ����з�ʽ�����Σ���ͥסַ
	cout << "���ϱ���Ϣ��Ա��";
	while (ifs >> name && ifs >> ID && ifs >> phone && ifs >> startLoc && ifs >> way && ifs >> wayID && ifs >> homeLoc)
	{
		cout << name << " ";
	}
	cout << endl;
	cout << "������Ҫ������Ϣ������" << endl;
	cin >> n;
	string arr[100];
	cout << "������Ҫ�������˵�����" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i <n; i++)
	{
		
		name1=arr[i];
		//���ļ�
		ifstream ifs;
		ifs.open(INFOMATION, ios::in);//�û��������֤�ţ��绰�ţ�ʼ���أ����з�ʽ�����Σ���ͥסַ
		while (ifs >> name && ifs >> ID && ifs >> phone && ifs >> startLoc && ifs >> way && ifs >> wayID && ifs >> homeLoc)
		{
			if (name == name1)
			{
				ofstream ofs;
				ofs.open(NOTICE, ios::out | ios::app);
				ofs << "\n" << name << " " << phone << " " << startLoc << " " << way << " "<<wayID << " " << homeLoc;
			}
		}
	}
	cout << "���淢�����";
	system("pause");
	system("cls");
}
