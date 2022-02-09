//流动人员类
#include<iostream>
using namespace std;
#include"Mobile.h"

//默认构造
Mobile::Mobile()
{

}
//有参构造（姓名即用户名，密码，身份证号，电话号，始发地，出行方式，车次，家庭住址）
Mobile::Mobile(string name, string pwd)
{

}

//菜单界面
void Mobile::operMenu()
{
	cout << "欢迎流动人员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.查看公告            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.填报信息            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}
//流动人员子界面
void Mobile::mobileMenu(Identity*& mobile)
{
	while (true)
	{
		//管理员菜单
		mobile->operMenu();
		Mobile* man = (Mobile*)mobile;

		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "查看公告" << endl;
			man->showNotice();
		}
		else if (select == 2)
		{
			cout << "填报信息" << endl;
			man->addInfo();
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
void Mobile::showNotice()
{

}

//填报信息
void Mobile::addInfo()
{

}