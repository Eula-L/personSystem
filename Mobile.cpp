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
	cout << "欢迎流动人员"  << "登录！" << endl;
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
		while (1)
		{
			if (!(cin >> select))
			{
				cout << "输入不合法，请重新输入\n";
				cin.clear(); // 清除输入流错误标记
				cin.ignore(1024, '\n');// 取走刚才输入流中的字符
				// cin.ignore()默认取走一个字符
			}
			else
				break;
		}
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
	MyStruct my;
	//string name;
	//string phone;
	//string startLoc;
	//int way;//1：火车2：客车3：飞机4：其他
	//string wayID;
	//string homeLoc;
	//读文件
	ifstream ifs;
	ifs.open(NOTICE, ios::in);//用户名，身份证号，电话号，始发地，出行方式，车次，家庭住址
	while (ifs >> my.name && ifs >> my.phone && ifs >> my.startLoc && ifs >> my.way && ifs >> my.wayID && ifs >> my.homeLoc)
	{
		cout << setw(15) << std::left << my.name << setw(15) << std::left << my.phone << setw(15) << std::left << my.startLoc;
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

//填报信息
void Mobile::addInfo()
{
	//存储数据
	MyStruct my;
	cout << "请输入您的姓名、身份证号、电话号以及始发地，用空格隔开！" << endl;
	cin >> my.name >> my.ID >> my.phone >> my.startLoc;
	cout << "请输入你的交通方式：火车\t客车\t飞机\t其他" << endl;
	string way1;
	cin >> way1;
	if (way1 == "火车")
	{
		my.way = 1;
	}
	else if (way1 == "客车")
	{
		my.way = 2;
	}
	else if (way1 == "飞机")
	{
		my.way = 3;
	}
	else
	{
		my.way = 4;
	}
	cout << "请输入你的车次/航班：" << endl;
	cin >> my.wayID;
	cout << "请输入你的家庭住址：" << endl;
	cin >> my.homeLoc;
	cout << "请核实信息" << endl;
	cout <<"姓名：" << my.name << " " <<"身份证号：" << my.ID << " "<<"电话号：" << my.phone << " "<<"始发地：" << my.startLoc << " "<<"交通方式：";
	if (my.way == 1)
	{
		cout << "火车" << " ";
	}
	else if (my.way == 2)
	{
		cout << "客车" << " ";
	}
	else if (my.way == 3)
	{
		cout << "飞机" << " ";
	}
	else if(my.way==4)
	{
		cout << "其他" << " ";
	}

	if (my.way == 1|| my.way==2)
	{
		cout << "车次：";
	}
	else if (my.way == 3)
	{
		cout << "航班号：" ;
	}
	else if (my.way == 4)
	{
		cout << "其他：";
	}
	cout << my.wayID << " ";
	cout << "家庭住址：" << my.homeLoc << endl;
	cout << "是否确认？(1:确认、2：重新输入）";
	int con = 0;
	cin >> con;
	if (con == 1)
	{
		ofstream ofs;
		ofs.open(INFOMATION, ios::out | ios::app);
		ofs << "\n" << my.name << " " << my.ID << " " << my.phone<<" " << my.startLoc << " " << my.way << " " << my.wayID << " " << my.homeLoc;
		cout << "上报完成" << endl;
	}
	else
	{
		addInfo();
	}
	system("pause");
	system("cls");
}
