//抽象出身份基类
#pragma once
#include<iostream>
#include<string>
using namespace std;
struct MyStruct
{
	string name;
	string ID;
	string phone;
	string startLoc;
	int way = 0;//1：火车2：客车3：飞机4：其他
	string wayID;
	string homeLoc;
};

//身份抽象类
class Identity
{
public:
	//操作菜单
	virtual void operMenu()=0;
	string m_Name;//用户名
	string m_Pwd;//密码
	int val =0;//1、普通用户2、流动人员3、管理员
};