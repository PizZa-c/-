#pragma once
#include "identity.h"
#include <string>
#include <vector>
#include "computerroom.h"
#include "orderfile.h"
class Student :public Identity
{
public:
	//默认构造
	Student();

	//有参构造
	Student(int id, string name, string pwd);

	//菜单界面
	virtual void openmenu();

	//申请预约
	void applyorder();

	//查看我的预约
	void showmyorder();

	//查看所有预约
	void showallorder();

	//取消预约
	void cancelorder();

	//学生学号
	int s_id;

	//机房容器
	vector<Computerroom>vc;
};