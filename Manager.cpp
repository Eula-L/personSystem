//管理人员类
#include<iostream>
#include <fstream>
using namespace std;
#include "Identity.h"
#include "globalFile.h"
#include "Ordinary.h"
#include "Mobile.h"
#include "Manager.h"
//默认构造
Manager::Manager()
{

}
//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	
}

//选择菜单
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.审核信息            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看公告            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.更新公告            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          5.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
//管理员子界面
void Manager::managerMenu(Identity*& manager)
{
	while (true)
	{
		//管理员菜单
		manager->operMenu();
		Manager* man = (Manager*)manager;

		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 2)
		{
			cout << "审核信息" << endl;
			man->showInfo();
		}
		else if (select == 3)
		{
			cout << "查看公告" << endl;
			man->showNotice();
		}
		else if (select == 4)
		{
			cout << "更新公告" << endl;
			man->changeNotice();
		}
		else
		{
			delete man;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//管理账号
//查看账号
void Manager::showPerson()
{

}

//查看当前上报信息
void Manager::showInfo()
{

}
//查看公告
void Manager::showNotice()
{

}
//更新公告
void Manager::changeNotice()
{

}
