#include "manage.h"
#include "settingfile.h"
#include <algorithm>
#include <string>
//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���
Manager::Manager(string name, string psw)
{
	//��ʼ����Ϣ
	this->name = name;
	this->password = psw;
	initvector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	Computerroom com;
	while (ifs >> com.c_id && ifs >> com.c_maxnum)
	{
		vc.push_back(com);
	}
	ifs.close();
	cout << "��������Ϊ:" << vc.size() << endl;
}

//�˵�
void Manager::openmenu()
{
	cout << "-------------------------------��ӭ������ֻ���ͻ���ԤԼϵͳ-------------------------------" << endl;
	cout << endl;
	cout << "��ӭ����Ա" << this->name << "��¼" << endl;
	cout << "                -----------------------------------------" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             1������˺�                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             2���鿴�˺�                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             3���鿴������Ϣ             |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             4�����ԤԼ��¼             |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             0��ע����¼                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "                -----------------------------------------" << endl;
	cout << endl;
 }

//����˺�
void Manager::addperson()
{
	cout << "��������Ҫ��ӵ�����:" << endl;
	cout << "1��ѧ��" << endl;
	cout << "2����ʦ" << endl;
	string filename;//�����ļ���
	string tip;//��ʾID��
	string errortip;
	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		filename = STUDENT_FILE;
		tip = "������ѧ��:";
		errortip = "ѧ���ظ�������������:";
	}
	else if (select == 2)
	{
		filename = TEACHER_FILE;
		tip = "������ְ�����:";
		errortip = "ְ�����ظ�������������:";
	}
	ofs.open(filename, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkrepeat(id, select);
		if (ret)
		{
			cout << errortip << endl;
		}
		else
		{
			break;
		}
	}
	
	cout << "����������:" << endl;
	cin >> name;
	cout << "�������½����:" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << endl;
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->initvector();
}


void printvs(Student&s)
{
	cout << "ѧ��:" << s.s_id << " ����:" << s.name << " ����:" << s.password << endl;
}
void printvt(Teacher& s)
{
	cout << "ְ����:" << s.m_empid << " ����:" << s.name << " ����:" << s.password << endl;
}
//�鿴�˺�
void Manager::showperson()
{
	cout << "��ѡ��鿴������" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;
	int select;
	cin >> select;
	if (select == 1)		
	{
		//�鿴ѧ��
		cout << "����ѧ����Ϣ����:" << endl;
		for_each(vs.begin(), vs.end(), printvs);
	}
	else
	{
		cout << "������ʦ��Ϣ����:" << endl;
		for_each(vt.begin(), vt.end(), printvt);
		//�鿴��ʦ
	}
	system("pause");
	system("cls");
}

void printvc(Computerroom & c)
{
	cout << "����ID��"<< c.c_id << " ��������:" << c.c_maxnum << endl;
}
//�鿴������Ϣ
void Manager::showcomputer()
{
	cout << "������Ϣ����:" << endl;
	for_each(vc.begin(), vc.end(), printvc);
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanfile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ�!" << endl;
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initvector()
{
	//ȷ���ļ�Ϊ��
	vs.clear();
	vt.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Student s;

	while (ifs >> s.s_id && ifs >> s.name && ifs >> s.password)
	{
		vs.push_back(s);
	}
	cout << "��ǰѧ������Ϊ" << vs.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_empid && ifs >>t.name &&ifs>>t.password)
	{
		vt.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ" << vt.size() << endl;
	ifs.close();
}

//����ظ�
bool Manager::checkrepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vs.begin(); it != vs.end(); it++)
		{
			if (id == it->s_id)
				return true;
		}
	}
	else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vt.begin(); it != vt.end(); it++)
		{
			if (id == it->m_empid)
				return true;
		}
	}
	return false;
}
