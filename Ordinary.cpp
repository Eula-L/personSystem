//普通人类
#pragma once
#include<iostream>
#include<fstream>
#include <iomanip>//格式输出
using namespace std;
#include"Ordinary.h"
#include"globalFile.h"

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
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.注销登陆             |\n";
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
	//存储信息
	string name;
	string phone;
	string startLoc;
	int way;//1：火车2：客车3：飞机4：其他
	string wayID;
	string homeLoc;
	//读文件
	ifstream ifs;
	ifs.open(NOTICE, ios::in);//用户名，身份证号，电话号，始发地，出行方式，车次，家庭住址
	while (ifs >> name && ifs >> phone && ifs >> startLoc && ifs >> way && ifs >> wayID && ifs >> homeLoc)
	{
		cout << setw(15) << std::left << name << setw(15) << std::left << phone << setw(15) << std::left << startLoc;
		if (way == 1)
		{
			cout << setw(15) << std::left << "火车";
		}
		else if (way == 2)
		{
			cout << setw(15) << std::left << "客车";
		}
		else if (way == 3)
		{
			cout << setw(15) << std::left << "飞机";
		}
		else if (way == 4)
		{
			cout << setw(15) << std::left << "其他";
		}
		cout << setw(15) << std::left << wayID << setw(15) << std::left << homeLoc << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}
//更改用户类型
void Ordinary::changeType()
{

}
