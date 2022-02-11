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

//���Ϣ
void Mobile::addInfo()
{
	//�洢����
	string name;
	string ID;
	string phone;
	string startLoc;
	int way = 0;//1����2���ͳ�3���ɻ�4������
	string wayID;
	string homeLoc;
	cout << "�������������������֤�š��绰���Լ�ʼ���أ��ÿո������" << endl;
	cin >> name >> ID >> phone >> startLoc;
	cout << "��������Ľ�ͨ��ʽ����\t�ͳ�\t�ɻ�\t����" << endl;
	string way1;
	cin >> way1;
	if (way1 == "��")
	{
		way = 1;
	}
	else if (way1 == "�ͳ�")
	{
		way = 2;
	}
	else if (way1 == "�ɻ�")
	{
		way = 3;
	}
	else
	{
		way = 4;
	}
	cout << "��������ĳ���/���ࣺ" << endl;
	cin >> wayID;
	cout << "��������ļ�ͥסַ��" << endl;
	cin >> homeLoc;
	cout << "���ʵ��Ϣ" << endl;
	cout <<"������" << name << " " <<"���֤�ţ�" << ID << " "<<"�绰�ţ�" << phone << " "<<"ʼ���أ�" << startLoc << " "<<"��ͨ��ʽ��";
	if (way == 1)
	{
		cout << "��" << " ";
	}
	else if (way == 2)
	{
		cout << "�ͳ�" << " ";
	}
	else if (way == 3)
	{
		cout << "�ɻ�" << " ";
	}
	else if(way==4)
	{
		cout << "����" << " ";
	}

	if (way == 1||way==2)
	{
		cout << "���Σ�";
	}
	else if (way == 3)
	{
		cout << "����ţ�" ;
	}
	else if (way == 4)
	{
		cout << "������";
	}
	cout << wayID << " ";
	cout << "��ͥסַ��" << homeLoc << endl;
	cout << "�Ƿ�ȷ�ϣ�(1:ȷ�ϡ�2���������룩";
	int con = 0;
	cin >> con;
	if (con == 1)
	{
		ofstream ofs;
		ofs.open(INFOMATION, ios::out | ios::app);
		ofs << "\n" << name << " " << ID << " " <<phone<<" " << startLoc << " " << way << " " << wayID << " " << homeLoc;
		cout << "�ϱ����" << endl;
	}
	else
	{
		addInfo();
	}
	system("pause");
	system("cls");
}
