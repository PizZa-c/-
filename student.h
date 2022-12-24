#pragma once
#include "identity.h"
#include <string>
#include <vector>
#include "computerroom.h"
#include "orderfile.h"
class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void openmenu();

	//����ԤԼ
	void applyorder();

	//�鿴�ҵ�ԤԼ
	void showmyorder();

	//�鿴����ԤԼ
	void showallorder();

	//ȡ��ԤԼ
	void cancelorder();

	//ѧ��ѧ��
	int s_id;

	//��������
	vector<Computerroom>vc;
};