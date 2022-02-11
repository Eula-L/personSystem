//流动人员类
#include<iostream>
#include<fstream>
#include <iomanip>//格式输出
using namespace std;
#include"Mobile.h"
#include"globalFile.h"


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

//填报信息
void Mobile::addInfo()
{
	//存储数据
	string name;
	string ID;
	string phone;
	string startLoc;
	int way = 0;//1：火车2：客车3：飞机4：其他
	string wayID;
	string homeLoc;
	cout << "请输入您的姓名、身份证号、电话号以及始发地，用空格隔开！" << endl;
	cin >> name >> ID >> phone >> startLoc;
	cout << "请输入你的交通方式：火车\t客车\t飞机\t其他" << endl;
	string way1;
	cin >> way1;
	if (way1 == "火车")
	{
		way = 1;
	}
	else if (way1 == "客车")
	{
		way = 2;
	}
	else if (way1 == "飞机")
	{
		way = 3;
	}
	else
	{
		way = 4;
	}
	cout << "请输入你的车次/航班：" << endl;
	cin >> wayID;
	cout << "请输入你的家庭住址：" << endl;
	cin >> homeLoc;
	cout << "请核实信息" << endl;
	cout <<"姓名：" << name << " " <<"身份证号：" << ID << " "<<"电话号：" << phone << " "<<"始发地：" << startLoc << " "<<"交通方式：";
	if (way == 1)
	{
		cout << "火车" << " ";
	}
	else if (way == 2)
	{
		cout << "客车" << " ";
	}
	else if (way == 3)
	{
		cout << "飞机" << " ";
	}
	else if(way==4)
	{
		cout << "其他" << " ";
	}

	if (way == 1||way==2)
	{
		cout << "车次：";
	}
	else if (way == 3)
	{
		cout << "航班号：" ;
	}
	else if (way == 4)
	{
		cout << "其他：";
	}
	cout << wayID << " ";
	cout << "家庭住址：" << homeLoc << endl;
	cout << "是否确认？(1:确认、2：重新输入）";
	int con = 0;
	cin >> con;
	if (con == 1)
	{
		ofstream ofs;
		ofs.open(INFOMATION, ios::out | ios::app);
		ofs << "\n" << name << " " << ID << " " <<phone<<" " << startLoc << " " << way << " " << wayID << " " << homeLoc;
		cout << "上报完成" << endl;
	}
	else
	{
		addInfo();
	}
	system("pause");
	system("cls");
}
