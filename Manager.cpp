//������Ա��
#include<iostream>
using namespace std;
#include"Manager.h"

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
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
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
