#pragma once
#include <iostream>
using namespace std;

class Identity {
public:
	virtual void openmenu() = 0;//菜单纯虚函数

	string name;//用户名
	string password;//密码
};