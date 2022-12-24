#include "student.h"
#include <string>
#include <fstream>
#include "settingfile.h"
#include <vector>
//�вι���
Student::Student(int id, string name, string pwd)
{
	//��ʼ����Ϣ
	this->name = name;
	this->s_id = id;
	this->password = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		return;
	}

	Computerroom p;
	while (ifs >> p.c_id && ifs >> p.c_maxnum)
	{

		vc.push_back(p);
	}
	ifs.close();

}

//Ĭ�Ϲ���
Student::Student()
{

}

//�˵�����
void Student::openmenu()
{
	cout << "-------------------------------��ӭ������ֻ���ͻ���ԤԼϵͳ-------------------------------" << endl;
	cout << endl;
	cout << "��ӭѧ������" << this->name << "��¼"<< endl;
	cout << "                -----------------------------------------" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             1������ԤԼ                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             2���鿴����ԤԼ             |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             3���鿴������ԤԼ           |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             4��ȡ��ԤԼ                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             0��ע����¼                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "                -----------------------------------------" << endl;
	cout << endl;
}

//����ԤԼ
void Student::applyorder()
{
	cout << "��������ʱ��Ϊ��һ������" << endl;
	cout << "����������ԤԼ��ʱ��:" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	int date;
	int interval;//ʱ���
	int room;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
			break;
		else
			cout << "������������������" << endl;
	}
	cout << "����������ԤԼ��ʱ���:" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
			break;
		else
			cout << "������������������" << endl;
	}
	cout << "��ѡ�����:" << endl;
	cout << vc[0].c_id << "�Ż�������Ϊ:" << vc[0].c_maxnum << endl;
	cout << vc[1].c_id << "�Ż�������Ϊ:" << vc[1].c_maxnum << endl;
	cout << vc[2].c_id << "�Ż�������Ϊ:" << vc[2].c_maxnum << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
			break;
		else
			cout << "������������������" << endl;
	}
	cout << "ԤԼ�ɹ��������!" << endl;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "id:" << this->s_id << " ";
	ofs << "interval:" << interval << " ";
	ofs << "name:" << this->name << " ";
	ofs << "room:" << room << " ";
	ofs << "status:" << 1 << endl;
	ofs.close();
	system("pause");
	system("cls");
}

//�鿴�ҵ�ԤԼ
void Student::showmyorder()
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
		//.c_strתc����ַ��� atoiתint
		if (this->s_id == atoi(o.mdata[i]["id"].c_str()))//�ҵ�����ԤԼ
		{
			cout << "ԤԼ����:��" << o.mdata[i]["date"];
			cout << " ʱ���:" << (o.mdata[i]["interval"] == "1" ? "����": "����");
			cout << " �������" << o.mdata[i]["room"];
			string status=" ״̬";
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
	}
	system("pause");
	system("cls");
		
}

//�鿴����ԤԼ
void Student::showallorder()
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
		cout << i+1 <<"��";
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

//ȡ��ԤԼ
void Student::cancelorder()
{
	Orderfile o;
	if (o.m_size == 0) {
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ������������Ҫȡ���ļ�¼:" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < o.m_size; i++)
	{
		if (atoi(o.mdata[i]["id"].c_str()) == this->s_id)
		{
			if (o.mdata[i]["status"] == "1" || o.mdata[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "��";
				cout << "ԤԼ����:��" << o.mdata[i]["date"];
				cout << " ʱ���:" << (o.mdata[i]["interval"] == "1" ? "����" : "����");
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
				cout << status << endl;
			}
		}
	}
	cout << "��������Ҫȡ���ļ�¼,0������" << endl;
	int select;
	while (true)
	{
		cin >> select;
		if (select >= 0&&select<=v.size()) 
		{
			if (select == 0)
				break;
			else
			{
				o.mdata[v[select - 1]]["status"] = "0";
				o.updateorder();
				cout << "��ȡ��ԤԼ��" << endl;
				break;
			}
		}
		else
		{
			cout << "��������ȷ������:" << endl;
		}
			
	}
	system("pause");
	system("cls");
	
}
