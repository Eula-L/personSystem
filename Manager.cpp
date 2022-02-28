//管理人员类
#include<iostream>
#include <fstream>
#include <iomanip>//格式输出
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
	cout << "\t\t|          4.清空公告            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          5.更新公告            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          6.注销登录            |\n";
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
			cout << "清空公告" << endl;
			man->cleanNotice();
		}
		else if (select == 5)
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
	

	string fName;
	string fPwd;
	int sta = 0;//txt中第三列表示身份：1、普通人2、流动人员3、管理员
	for (int i = 3; i > 0; i--)
	{
		if (i == 3)
		{
			
			cout << "管理员账号信息" << endl;
		}
		else if (i == 2)
		{
			cout << "流动人员账号信息" << endl;
		}
		else 
		{
			cout << "普通用户账号信息" << endl;
		}
		//读文件
		ifstream ifs;
		ifs.open(PEOPLE, ios::in);//这种方法读出的文件只能输出一次
		while (ifs >> fName && ifs >> fPwd && ifs >> sta)
		{
			if (sta == i)
			{
				//应该做一个输出对齐
				cout << fName << "   " << fPwd << endl;
			}
		}
		cout << endl;
	}
	system("pause");
	system("cls");
	return;
}

//查看当前上报信息
void Manager::showInfo()
{
	//存储信息
	MyStruct my;
	cout << setw(15) << std::left << "姓名" << setw(15) << std::left << "身份证号" << setw(15) << std::left << "电话号" << setw(15) << std::left << "始发地"<<setw(15) << std::left <<"出行方式"<<setw(15) << std::left <<"车次"<<setw(15) << std::left << "家庭住址"<<endl;
	//读文件
	ifstream ifs;
	ifs.open(INFOMATION, ios::in);//用户名，身份证号，电话号，始发地，出行方式，车次，家庭住址
	while (ifs >> my.name && ifs >> my.ID && ifs >> my.phone && ifs >> my.startLoc && ifs >> my.way && ifs >> my.wayID && ifs >> my.homeLoc)
	{
		
		cout << setw(15) << std::left << my.name << setw(15) << std::left << my.ID << setw(15) << std::left << my.phone << setw(15) << std::left << my.startLoc;
		if (my.way == 1)
		{
			cout<< setw(15) << std::left << "火车";
		}
		else if(my.way==2)
		{
			cout<< setw(15) << std::left << "客车";
		}
		else if(my.way==3)
		{
			cout << setw(15) << std::left << "飞机";
		}
		else if(my.way==4)
		{
			cout << setw(15) << std::left << "其他";
		}
		cout << setw(15) << std::left << my.wayID << setw(15) << std::left << my.homeLoc << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}
//查看公告
void Manager::showNotice()
{
	//存储信息
	MyStruct my;
	//读文件
	ifstream ifs;
	ifs.open(NOTICE, ios::in);//用户名，身份证号，电话号，始发地，出行方式，车次，家庭住址
	while (ifs >> my.name  && ifs >> my.phone && ifs >> my.startLoc && ifs >> my.way && ifs >> my.wayID && ifs >> my.homeLoc)
	{
		cout << setw(15) << std::left << my.name  << setw(15) << std::left << my.phone << setw(15) << std::left << my.startLoc;
		if (my.way == 1)
		{
			cout << setw(15) << std::left << "火车";
		}
		else if (my.way == 2)
		{
			cout << setw(15) << std::left << "客车";
		}
		else if (my.way == 3)
		{
			cout << setw(15) << std::left << "飞机";
		}
		else if (my.way == 4)
		{
			cout << setw(15) << std::left << "其他";
		}
		cout << setw(15) << std::left << my.wayID << setw(15) << std::left << my.homeLoc << endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}

//清空公告
void Manager::cleanNotice()
{	
		fstream file(NOTICE, ios::out);
		system("pause");
		system("cls");
}

//更新公告
void Manager::changeNotice()
{
	//向账号信息文件中写入新的用户信息
	//并且删除上报信息文件中对应的人的信息
	int n;
	string name1;
	MyStruct my;
	ifstream ifs;
	ifs.open(INFOMATION, ios::in);//用户名，身份证号，电话号，始发地，出行方式，车次，家庭住址
	cout << "已上报信息人员：";
	while (ifs >> my.name && ifs >> my.ID && ifs >> my.phone && ifs >> my.startLoc && ifs >> my.way && ifs >> my.wayID && ifs >> my.homeLoc)
	{
		cout << my.name << " ";
	}
	cout << endl;
	cout << "请输入要发布信息的人数" << endl;
	cin >> n;
	string arr[1000];
	cout << "请输入要发布的人的姓名" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i <n; i++)
	{
		
		name1=arr[i];
		//读上报信息文件
		ifstream ifs;
		ifs.open(INFOMATION, ios::in);//用户名，身份证号，电话号，始发地，出行方式，车次，家庭住址
		while (ifs >> my.name && ifs >> my.ID && ifs >> my.phone && ifs >> my.startLoc && ifs >> my.way && ifs >> my.wayID && ifs >> my.homeLoc)
		{
			if (my.name == name1)
			{	//将读取的信息写入到公告中
				ofstream ofs;
				ofs.open(NOTICE, ios::out | ios::app);
				ofs << "\n" << my.name << " " << my.phone << " " << my.startLoc << " " << my.way << " "<< my.wayID << " " << my.homeLoc;
			}
		}
	}
	cout << "公告发布完成";
	ifs.close();
	system("pause");
	system("cls");
}
