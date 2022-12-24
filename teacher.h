#pragma once
#include <iostream>
#include "identity.h"
using namespace std;

class Teacher :public Identity
{
public:
	//默认构造
	Teacher();

	//有参构造
	Teacher(int id, string name,  string psw);

	//菜单
	virtual void openmenu();

	//查看所有预约
	void showallorder();

	//审核预约
	void validorder();

	int m_empid;//教师编号
};