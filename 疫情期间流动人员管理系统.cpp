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
//注册
void addPerson();
//检测重复 参数:(传入id，传入类型) 返回值：(true 代表有重复，false代表没有重复)
bool checkRepeat(string name, int type);




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
			system("cls");
			addPerson();
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
				person = new Ordinary(name, pwd);
				//进入普通用户子页面
				Ordinary* menu = new Ordinary;
				menu->ordinaryMenu(person);

			}
			else if (sta == 2)
			{
				person = new Mobile(name, pwd);
				//进入流动人员子界面
				
			}
			else if (sta == 3)
			{
				person = new Manager(name, pwd);
				Manager* menu = new Manager;
				//进入管理员子界面
				menu->managerMenu(person);
			}
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

//注册
void addPerson()
{
	system("cls");
	ofstream ofs;
	string name;
	string pwd1;
	string pwd2;
	int cla = 0;//用于记录类型
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               \n";
	cout << "\t\t|          1.普通用户           \n";
	cout << "\t\t|                               \n";
	cout << "\t\t|          2.流动人员           \n";
	cout << "\t\t|                               \n";
	cout << "\t\t|          3.管理员            \n";
	cout << "\t\t|                               \n";
	cout << "\t\t -------------------------------\n";
	cout << "请选择要注册的账户类型"<<endl;
	cin >> cla;
	cout << "请输入姓名" << endl;
	cin >> name;

	//避免用户名重复
	if (checkRepeat(name, cla)) //有重复
	{
		cout << "用户名已存在,请重新输入" << endl;
		system("pause");
		addPerson();
	}
	cout << "请输入密码" << endl;
	cin >> pwd1;
	cout << "请再次输入密码" << endl;
	cin >> pwd2;

	//检验两次密码是否相同
	if (pwd1 == pwd2)
	{
		//向公告信息文件中写入新的用户信息
		ofs.open(NOTICE, ios::out | ios::app);
		ofs <<"\n"<< name << " " << pwd1 << " " << cla << endl;
		cout << "注册成功" << endl;
		system("pause");
		system("cls");
		return;
	}
	else
	{
		cout << "两次输入的密码不相同，请重新输入" << endl;//但是这种方法用户名也得重新输入
		system("pause");
		system("cls");
		addPerson();
	}
	
}
//检测重复 参数:(传入id，传入类型) 返回值：(true 代表有重复，false代表没有重复)
bool checkRepeat(string name, int type)
{
	//读取账号文件中信息
	ifstream ifs;
	ifs.open(PEOPLE, ios::in);	
	string e_name;
	string e_pwd;
	int e_val;
	while (ifs >> e_name && ifs >> e_pwd && ifs >> e_val)
	{
		if (name == e_name && type == e_val)
		{
			return true;
		}
	}
	return false;
}
