//������Ա��
/*��Ҫ���ܣ�
* �鿴����
* ���Ϣ�����ϱ����˵����������֤�ţ��绰�ţ���ʼ�أ���ͨ��ʽ������/�����
* �鿴��Ϣ�����鿴�������ϱ�����Ϣ
* ע����¼�������ص�¼����
*/
#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"

class Mobile :public Identity
{
public:
	//Ĭ�Ϲ���
	Mobile();
	//�вι��죨�������û��������룬���֤�ţ��绰�ţ�ʼ���أ����з�ʽ�����Σ���ͥסַ��
	//Mobile(string name, string pwd, string id, string phone_id, string start, int way, string way_id,string home);
	Mobile(string name, string pwd);

	//�˵�����
	virtual void operMenu();
	//������Ա�ӽ���
	void mobileMenu(Identity*& mobile);
	//ע��
	void addPerson();
	
	//�鿴����
	void showNotice();
	//���Ϣ
	void addInfo();

	//��������
	string m_Id;
	string m_phone_id;
	string m_Start;
	int m_Way;
	string m_May_id;
	string m_Home;
};