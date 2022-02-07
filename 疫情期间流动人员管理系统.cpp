#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Identity.h"
#include "globalFile.h"
#include "Ordinary.h"
#include "Mobile.h"
#include "Manager.h"

//by:北辰
// 输出主界面
void priMenu();

//准备登录
void log(bool boo);
//登录
void LoginIn(string fileName, string name, string pwd, bool val);

//管理员菜单
void managerMenu(Identity*& Manager);


int main()
{
	//创建一个变量记录选择
	int choose = 0;
	while (true)
	{
		//输出主界面
		priMenu();
		cout << "请输入您的选择：\n";
		cin >> choose;
		bool val = false;//记录登录状态
		switch (choose)
		{
		case 1://登录
			//准备接受用户的信息
			log(val);
			break;
		case 2://注册
			break;
		case 3://退出系统
			cout << "感谢您使用！" << endl;
			return 0;
			system("pause");
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");//刷新界面，相当于删除错误输出和提示
			break;
		}
	}
	system("pause");
	return 0;
}

//输出主界面
void priMenu()
{
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.登    录           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.注    册           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.退    出           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
}
//准备登录
void log(bool boo)
{
	string name;
	string pwd;
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;
	system("cls");
	LoginIn(PEOPLE, name, pwd, boo);
}

//登录LoginIn
void LoginIn(string fileName, string name, string pwd, bool val)
{
	//父类指针，用于指向子类对象
	Identity* person = NULL;
	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	string fName;
	string fPwd;
	int sta = 0;//txt中第三列表示身份：1、普通人2、流动人员3、管理员
	while (ifs >> fName && ifs >> fPwd && ifs >> sta)
	{
		if (name == fName && pwd == fPwd)
		{
			val = true;
			if (sta == 1)
			{
				cout << "普通用户："<<fName<<endl;
				person = new Ordinary(name, pwd);
				//进入普通用户子页面
			}
			else if (sta == 2)
			{
				cout << "流动人员：" << fName << endl;
				person = new Mobile(name, pwd);
				//进入流动人员子界面
			}
			else if (sta == 3)
			{
				cout << "管理员：" << fName << endl;
				person = new Manager(name, pwd);
				//进入管理员子界面
				managerMenu(person);
			}
			cout << "验证登录成功！" << endl;

			system("pause");
			system("cls");

			return;
		}
	}
	if (!val)
	{
		priMenu();
		cout << "用户名或密码错误\n请重新输入密码" << endl;
		log(val);
	}
}
//管理员子页面
void managerMenu(Identity* & manager)
{
	while (true)
	{
		//管理员菜单
		manager->operMenu();
		Manager* man = (Manager*)manager;

		int select = 0;

		cin >> select;

		if (select == 1)  //添加账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 2) //查看账号
		{
			cout << "审核信息" << endl;
			man->showInfo();
		}
		else if (select == 3) //查看机房
		{
			cout << "查看公告" << endl;
			man->showNotice();
		}
		else if (select == 4) //清空预约
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