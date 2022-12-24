#pragma once
#include <iostream>
using namespace std;
#include "settingfile.h"
#include <fstream>
#include <map>

class Orderfile
{
public:

	//构造函数
	Orderfile();

	//更新预约记录
	void updateorder();

	//记录预约条数
	int m_size;

	//记录所有预约的容器
	map<int, map<string, string>>mdata;
};