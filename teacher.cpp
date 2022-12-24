#include "teacher.h"
#include "orderfile.h"
#include <vector>
//Ĭ�Ϲ���
Teacher::Teacher()
{

}

//�вι���
Teacher::Teacher(int id, string name,  string psw)
{
	this->m_empid = id;
	this->name = name;
	this->password = psw;
}

//�˵�
void Teacher::openmenu()
{
	cout << endl;
	cout << "��ӭ��ʦ" << this->name << "��¼" << endl;
	cout << "                -----------------------------------------" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             1���鿴������ԤԼ           |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             2�����ԤԼ                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             0��ע����¼                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "                -----------------------------------------" << endl;
	cout << endl;
}

//�鿴����ԤԼ
void Teacher::showallorder()
{
	Orderfile o;
	if (o.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < o.m_size; i++)
	{
		cout << i + 1 << "��";
		cout << " ԤԼ����:��" << o.mdata[i]["date"];
		cout << " ʱ���:" << (o.mdata[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ��" << o.mdata[i]["id"];
		cout << " �������" << o.mdata[i]["room"];
		string status = " ״̬";
		if (o.mdata[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (o.mdata[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (o.mdata[i]["status"] == "-1")
		{
			status += "��˲�ͨ��";
		}
		else
		{
			status += "ԤԼ�Ѿ�ȡ��";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");

}

//���ԤԼ
void Teacher::validorder()
{
	Orderfile o;
	if (o.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼����" << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < o.mdata.size(); i++)
	{
		if (o.mdata[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "��" << "ԤԼ����:��" << o.mdata[i]["date"];
			cout << " ʱ��Σ�" << (o.mdata[i]["interval"] == "1" ? "����" : "����");
			cout << " ѧ�����:" << o.mdata[i]["id"];
			cout << " �������:" << o.mdata[i]["room"];
			cout << "״̬: �����" << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼��0������" << endl;
	int select = 0;//�����û�ѡ���ԤԼ��¼
	int ret = 0;//����ԤԼ�Ľ���ļ�¼

	while (true)
	{
		cin >> select;
		if (select >= 0)
		{
			if (select == 0)
				break;
			cout << "��������˽��:" << endl;
			cout << "1��ͨ��" << endl;
			cout << "2����ͨ��" << endl;
			cin >> ret;
			if (ret == 1)
			{
				//ͨ�����
				o.mdata[v[select-1]]["status"] = "2";
			}
			else
			{
				o.mdata[v[select - 1]]["status"] = "-1";
				//��ͨ��
			}
			o.updateorder();//����ԤԼ��¼
			cout << "������" << endl;
			break;
		}
		
		else
		{
			cout << "��������Ч����:" << endl;
		}
	}
	system("pause");
	system("cls");
}

