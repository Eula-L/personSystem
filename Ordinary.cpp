//普通人类
#pragma once
#include<iostream>
using namespace std;
#include"Ordinary.h"

//默认构造
Ordinary::Ordinary()
{

}
//有参构造
Ordinary::Ordinary(string name, string pwd)
{

}

//菜单界面
void Ordinary::operMenu()
{
	cout << "欢迎普通用户：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.查看公告             |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.更改账户类型         |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.注销登陆             |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//普通用户子界面
void Ordinary::ordinaryMenu(Identity*& ordinary)
{
	while (true)
	{
		//普通用户菜单
		ordinary->operMenu();
		Ordinary* man = (Ordinary*)ordinary;

		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "查看公告" << endl;
			man->showNotice();
		}
		else if (select == 2)
		{
			cout << "更改账户类型" << endl;
			man->changeType();
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
//查看公告
void Ordinary::showNotice()
{

}
//更改用户类型
void Ordinary::changeType()
{

}
