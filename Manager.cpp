//管理人员类
#include<iostream>
#include <fstream>
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
	//初始化容器
	this->initVector();
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
	cout << "\t\t|          5.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

void Manager::initVector()
{
	//读取账号文件中信息
	ifstream ifs;
	ifs.open(PEOPLE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	vPer.clear();
	
	Ordinary i;
	int iOrdNum = 0; 
	int iMobNum = 0;
	int iManNum = 0;
	while (ifs >> i.m_Name && ifs >> i.m_Pwd && ifs >> i.val)
	{
		vPer.push_back(i);
		if (i.val == 1)
		{
			iOrdNum++;
		}
		else if (i.val == 2)
		{
			iMobNum++;
		}
		else if (i.val == 3)
		{
			iManNum++;
		}
	}
	cout << "当前普通用户数量为： " <<iOrdNum<< endl;
	cout << "当前流动人员数量为： " <<iManNum<< endl;
	cout << "当前管理员数量为： " << iManNum<< endl;
	ifs.close(); 
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
