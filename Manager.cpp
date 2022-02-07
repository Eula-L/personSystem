//管理人员类
#include<iostream>
using namespace std;
#include"Manager.h"

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
	cout << "\t\t|          4.更新公告            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}


//管理账号
//查看账号
void Manager::showPerson()
{

}

//查看当前上报信息
void Manager::showInfo()
{

}
//查看公告
void Manager::showNotice()
{

}
//更新公告
void Manager::changeNotice()
{

}
