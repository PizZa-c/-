#pragma once
#include <iostream>
using namespace std;
#include "settingfile.h"
#include <fstream>
#include <map>

class Orderfile
{
public:

	//���캯��
	Orderfile();

	//����ԤԼ��¼
	void updateorder();

	//��¼ԤԼ����
	int m_size;

	//��¼����ԤԼ������
	map<int, map<string, string>>mdata;
};