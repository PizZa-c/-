#pragma once
#include <iostream>
#include "identity.h"
using namespace std;

class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι���
	Teacher(int id, string name,  string psw);

	//�˵�
	virtual void openmenu();

	//�鿴����ԤԼ
	void showallorder();

	//���ԤԼ
	void validorder();

	int m_empid;//��ʦ���
};