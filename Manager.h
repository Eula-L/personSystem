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

	//注册
	void addPerson();
	//防止账号重复
	
	
	//管理账号
	//查看账号
	void showPerson();

	//查看当前上报信息
	void showInfo();
	//更新公告
	void changeNotice();
	//查看公告
	void showNotice();


};