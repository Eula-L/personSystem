#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#include"Identity.h"
#include"globalFile.h"
#include"Ordinary.h"
#include"Mobile.h"
#include"Manager.h"

//by:北辰

//登录LoginIn
void LoginIn(string fileName,int type)
{
	//父类指针，用于指向子类对象
	Identity* person = NULL;
	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);
	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	//准备接受用户的信息
	string name;
	string pwd;
	cout << "请输入姓名" << endl;
	cin >> name;
	cout << "请输入密码" << endl;
	cin >> pwd;

	//验证登录
	if (type == 1)
	{
		//普通人验证登录
		string fName;
		string fPwd;
		bool val = false;//用于记录登录验证
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "普通人验证登录成功！" << endl;
				val = true;
				system("pause");
				system("cls");
				person = new Ordinary(name, pwd);
				return;
			}
		}
		if (!val)
		{
			cout << "用户名或密码有误，请重新输入" << endl;
			LoginIn(ORDINARY_FILE, 1);
			return;
		}
	}
	else if (type == 2)
	{
		//流动人员验证登录
		string fName;
		string fPwd;
		bool val = false;//用于记录登录验证
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "流动人员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Mobile(name, pwd);
				return;
			}
		}
		if (!val)
		{
			cout << "用户名或密码有误，请重新输入" << endl;
			LoginIn(MOBILE_FILE, 2);
			return;
		}
	}
	else if (type == 3)
	{
		//管理员验证登录
		string fName;
		string fPwd;
		bool val = false;//用于记录登录验证
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证登录成功!" << endl;
				//登录成功后，按任意键进入管理员界面
				system("pause");
				system("cls");
				//创建管理员对象
				person = new Manager(name, pwd);
				return;
			}
		}
		if (!val)
		{
			cout << "用户名或密码有误，请重新输入" << endl;
			LoginIn(MANAGER_FILE, 3);
			return;
		}
		
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
		switch (choose)
		{
		case 1://登录
			system("cls");
			while (true)
			{
				int type;//用于记录选择的类
				cout << "\t\t -------------------------------\n";
				cout << "\t\t|                               |\n";
				cout << "\t\t|          1.普 通 人            |\n";
				cout << "\t\t|                               |\n";
				cout << "\t\t|          2.流动人员            |\n";
				cout << "\t\t|                               |\n";
				cout << "\t\t|          3.管理员              |\n";
				cout << "\t\t|                               |\n";
				cout << "\t\t -------------------------------\n";
				cout << "请输入您的账户类型：\n";
				cin >> type;
				switch (type)
				{
				case 1://普通人
					LoginIn(ORDINARY_FILE, 1);
					break;
				case 2://流动人员
					LoginIn(MOBILE_FILE, 2);
					break;
				case 3://管理员
					LoginIn(MANAGER_FILE, 3);
					break;
				default:
					cout << "输入有误，请重新选择！" << endl;
					system("pause");
					system("cls");//刷新界面，相当于删除错误输出和提示
					break;
				}
			}
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
