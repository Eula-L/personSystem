//流动人员类
/*主要功能：
* 查看公告
* 填报信息——上报个人的姓名，身份证号，电话号，起始地，交通方式，车次/航班号
* 注销登录——返回登录界面
*/
#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"

class Mobile :public Identity
{
public:
	//默认构造
	Mobile();
	//有参构造
	Mobile(string name, string pwd);
	//菜单界面
	virtual void operMenu();
	//流动人员子界面
	void mobileMenu(Identity*& mobile);
	//查看公告
	void showNotice();
	//填报信息
	void addInfo();
	//独有属性
	string m_Id;
	string m_phone_id;
	string m_Start;
	int m_Way;
	string m_May_id;
	string m_Home;
};