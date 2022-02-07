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
void LoginIn(string fileName, string name, string pwd, bool val);
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
	int shenfen = 0;
	while (ifs >> fName && ifs >> fPwd && ifs >> shenfen)
	{
		if (name == fName && pwd == fPwd)
		{
			val = true;
			if (shenfen == 1)
			{
				cout << "普通人";
				person = new Ordinary(name, pwd);
				//进入普通人子页面
			}
			else if (shenfen == 2)
			{
				cout << "流动人员";
				person = new Ordinary(name, pwd);
				//
			}
			else if (shenfen == 3)
			{
				cout << "管理员";
				person = new Ordinary(name, pwd);
				//
			}
			cout << "验证登录成功！" << endl;

			system("pause");
			system("cls");

			return;
		}
	}
	if (!val)
	{
		cout << "用户名或密码错误\n请重新输入密码" << endl;
		log( val);
	}
}

int main()
{
	//创建一个变量记录选择
	int choose = 0;
	while (true)
	{
		//输出登录界面
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.登    录           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.注    册           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "请输入您的选择：\n";
		cin >> choose;
		bool val = false;
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
