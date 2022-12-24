#pragma once
#include "identity.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "student.h"
#include "teacher.h"
#include "computerroom.h"
using namespace std;

class Manager :public Identity
{
public:
	//默认构造
	Manager();

	//有参构造
	Manager(string name, string psw);

	//菜单
	virtual void openmenu();

	//添加账号
	void addperson();

	//查看账号
	void showperson();

	//查看机房信息
	void showcomputer();

	//清空预约记录
	void cleanfile();

	//初始化容器
	void initvector();

	//学生容器
	vector<Student>vs;

	//老师容器
	vector<Teacher>vt;

	//机房信息容器
	vector<Computerroom>vc;
	
	//检测重复
	bool checkrepeat(int id, int type);
};