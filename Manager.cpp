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
	//��ʼ������
	this->initVector();
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

void Manager::initVector()
{
	//��ȡ�˺��ļ�����Ϣ
	ifstream ifs;
	ifs.open(PEOPLE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	vPer.clear();
	
	Ordinary i;
	int iOrdNum = 0; 
	int iMobNum = 0;
	int iManNum = 0;
	while (ifs >> i.m_Name && ifs >> i.m_Pwd && ifs >> i.val)
	{
		vPer.push_back(i);
		if (i.val == 1)
		{
			iOrdNum++;
		}
		else if (i.val == 2)
		{
			iMobNum++;
		}
		else if (i.val == 3)
		{
			iManNum++;
		}
	}
	cout << "��ǰ��ͨ�û�����Ϊ�� " <<iOrdNum<< endl;
	cout << "��ǰ������Ա����Ϊ�� " <<iManNum<< endl;
	cout << "��ǰ����Ա����Ϊ�� " << iManNum<< endl;
	ifs.close(); 
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
