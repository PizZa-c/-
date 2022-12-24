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
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string psw);

	//�˵�
	virtual void openmenu();

	//����˺�
	void addperson();

	//�鿴�˺�
	void showperson();

	//�鿴������Ϣ
	void showcomputer();

	//���ԤԼ��¼
	void cleanfile();

	//��ʼ������
	void initvector();

	//ѧ������
	vector<Student>vs;

	//��ʦ����
	vector<Teacher>vt;

	//������Ϣ����
	vector<Computerroom>vc;
	
	//����ظ�
	bool checkrepeat(int id, int type);
};