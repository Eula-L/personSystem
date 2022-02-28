//管理员类
/*
* 查看公告
* 管理所有账号
* 审核信息
* 发布、更新公告
*/
#pragma once
#include<iostream>
#include<vector>
using namespace std;
#include"Identity.h"

class Manager :public Identity
{
public:
	//默认构造
	Manager();
	//有参构造
	Manager(string name, string pwd);

	//选择菜单
	virtual void operMenu();
	//管理员子界面
	void managerMenu(Identity*& manager);
	//查看账号
	void showPerson();
	//查看当前上报信息
	void showInfo();
	//更新公告
	void changeNotice();
	//清空公告
	void cleanNotice();
	//查看公告
	void showNotice();


};