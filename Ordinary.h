//��ͨ�û���
/*��Ҫ���ܣ�
*	ע���˺�
*	��¼
*	�鿴����
*/
#pragma once
#include<iostream>
#include <iomanip>//���뻯���
using namespace std;
#include"Identity.h"

//��ͨ����
class Ordinary :public Identity
{
public:
	//Ĭ�Ϲ���
	Ordinary();
	//�вι���
	Ordinary(string name, string pwd);
	//�˵�����
	virtual void operMenu();
	//��ͨ�û��ӽ���
	void ordinaryMenu(Identity*& ordinary);
	//�鿴����
	void showNotice();
	//�����������ģ��
	template<typename T>
	void print(const T& t)
	{
		cout << setw(15) << std::left << t;//����룬ռ��15���ַ�
	}
};