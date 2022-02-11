//普通用户类
/*主要功能：
*	注册账号
*	登录
*	查看公告
*/
#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"

//普通人类
class Ordinary :public Identity
{
public:
	//默认构造
	Ordinary();
	//有参构造
	Ordinary(string name, string pwd);
	//菜单界面
	virtual void operMenu();
	//普通用户子界面
	void ordinaryMenu(Identity*& ordinary);
	//查看公告
	void showNotice();
};