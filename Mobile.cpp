//������Ա��
#include<iostream>
#include<fstream>
#include <iomanip>//��ʽ���
using namespace std;
#include"Mobile.h"
#include"globalFile.h"


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
	cout << "��ӭ������Ա"  << "��¼��" << endl;
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
		while (1)
		{
			if (!(cin >> select))
			{
				cout << "���벻�Ϸ�������������\n";
				cin.clear(); // ���������������
				cin.ignore(1024, '\n');// ȡ�߸ղ��������е��ַ�
				// cin.ignore()Ĭ��ȡ��һ���ַ�
			}
			else
				break;
		}
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
	//�洢��Ϣ
	MyStruct my;
	//string name;
	//string phone;
	//string startLoc;
	//int way;//1����2���ͳ�3���ɻ�4������
	//string wayID;
	//string homeLoc;
	//���ļ�
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

//���Ϣ
void Mobile::addInfo()
{
	//�洢����
	MyStruct my;
	cout << "�������������������֤�š��绰���Լ�ʼ���أ��ÿո������" << endl;
	cin >> my.name >> my.ID >> my.phone >> my.startLoc;
	cout << "��������Ľ�ͨ��ʽ����\t�ͳ�\t�ɻ�\t����" << endl;
	string way1;
	cin >> way1;
	if (way1 == "��")
	{
		my.way = 1;
	}
	else if (way1 == "�ͳ�")
	{
		my.way = 2;
	}
	else if (way1 == "�ɻ�")
	{
		my.way = 3;
	}
	else
	{
		my.way = 4;
	}
	cout << "��������ĳ���/���ࣺ" << endl;
	cin >> my.wayID;
	cout << "��������ļ�ͥסַ��" << endl;
	cin >> my.homeLoc;
	cout << "���ʵ��Ϣ" << endl;
	cout <<"������" << my.name << " " <<"���֤�ţ�" << my.ID << " "<<"�绰�ţ�" << my.phone << " "<<"ʼ���أ�" << my.startLoc << " "<<"��ͨ��ʽ��";
	if (my.way == 1)
	{
		cout << "��" << " ";
	}
	else if (my.way == 2)
	{
		cout << "�ͳ�" << " ";
	}
	else if (my.way == 3)
	{
		cout << "�ɻ�" << " ";
	}
	else if(my.way==4)
	{
		cout << "����" << " ";
	}

	if (my.way == 1|| my.way==2)
	{
		cout << "���Σ�";
	}
	else if (my.way == 3)
	{
		cout << "����ţ�" ;
	}
	else if (my.way == 4)
	{
		cout << "������";
	}
	cout << my.wayID << " ";
	cout << "��ͥסַ��" << my.homeLoc << endl;
	cout << "�Ƿ�ȷ�ϣ�(1:ȷ�ϡ�2���������룩";
	int con = 0;
	cin >> con;
	if (con == 1)
	{
		ofstream ofs;
		ofs.open(INFOMATION, ios::out | ios::app);
		ofs << "\n" << my.name << " " << my.ID << " " << my.phone<<" " << my.startLoc << " " << my.way << " " << my.wayID << " " << my.homeLoc;
		cout << "�ϱ����" << endl;
	}
	else
	{
		addInfo();
	}
	system("pause");
	system("cls");
}
