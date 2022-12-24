#include <iostream>
using namespace std;
#include "identity.h"
#include <fstream>
#include "settingfile.h"
#include "student.h"
#include "teacher.h"
#include "manage.h"
//����ѧ���Ӳ˵�����
void studentmenu(Identity*& student)
{

	while (true)
	{
		student->openmenu();

		//������ָ��תΪ����ָ����Ե������������ӿ�
		Student* stu = (Student*)student;
		//student->openmenu();
		int select = 0;
		cout << "���������ѡ��" << endl;
		cin >> select;
		if (select == 1)
		{
			//����ԤԼ
			stu->applyorder();
		}
		else if (select == 2)
		{
			//�鿴�ҵ�ԤԼ
			stu->showmyorder();
		}
		else if (select == 3)
		{
			//�鿴�����˵�ԤԼ
			stu->showallorder();
		}
		else if (select == 4)
		{
			//ȡ��ԤԼ
			stu->cancelorder();
		}
		else
		{
			//cout << "ע����¼"<< endl;
			delete stu;
			system("pause");
			system("cls");
			return;
		}
	}
}

//�������Ա�Ӳ˵�����
void managermenu(Identity* &manager)
{
	while (true)
	{
		manager->openmenu();
		
		//������ָ��תΪ����ָ����Ե������������ӿ�
		Manager* man = (Manager*)manager;
		//man->openmenu();
		int select = 0;
		cout << "���������ѡ��" << endl;
		cin >> select;
		if (select == 1)
		{
			//cout << "����˺�" << endl;
			man->addperson();
		}
		else if (select == 2)
		{
			//cout << "�鿴�˺�" << endl;
			man->showperson();
		}
		else if (select == 3)
		{
			//cout << "�鿴������Ϣ" << endl;
			man->showcomputer();
		}
		else if (select == 4)
		{
			//cout << "���ԤԼ��¼" << endl;
			man->cleanfile();
		}
		else
		{
			//cout << "ע����¼"<< endl;
			delete man;
			system("pause");
			system("cls");
			return;
		}
	}
}
//������ʦ�Ӳ˵�
void teachermenu(Identity* &teacher)
{
	while (true)
	{
		//�����Ӳ˵�����
		teacher->openmenu();

		Teacher* tea = (Teacher*)teacher;
		cout << "��������Ҫѡ��Ĳ���:" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//�鿴����ԤԼ
			tea->showallorder();
		}
		else if (select == 2)
		{
			//���ԤԼ
			tea->validorder();
		}
		else
		{
			delete tea;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return ;
		}
	}
}
//��¼����
void login(string filename, int type)
{
	//����ָ�룬���ڲ����������
	Identity* person = NULL;

	//���ļ�
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;

	if (type == 1)//ѧ��
	{
		cout << "���������ѧ��:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ����:" << endl;
		cin >> id;
	}
	cout << "�������û���:" << endl;
	cin >> name;
	cout << "����������: " << endl;
	cin >> pwd;
	if (type == 1)//ѧ��
	{
		//��Ա��Ϣ
		int fid;
		string fname;
		string fpsw;
		while (ifs >> fid && ifs >> fname && ifs >> fpsw)
		{
			if (fid == id && fname == name && pwd == fpsw)
			{
				cout << "ѧ����֤��½�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentmenu(person);
				return;
			}
		}
	}
	else if (type == 2)//��ʦ
	{
		//��Ա��Ϣ
		int fid;
		string fname;
		string fpsw;
		while (ifs >> fid && ifs >> fname && ifs >> fpsw)//ifs>>�����ȡ�ո�
		{
			if (fid == id && fname == name && pwd == fpsw)
			{
				cout << "��ʦ��֤��½�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id,name,pwd);
				teachermenu(person);
				return;
			}
		}
	}
	else //����Ա
	{
		//��Ա��Ϣ
		
		string fname;
		string fpsw;
		while (ifs >> fname && ifs >> fpsw)//ifs>>�����ȡ�ո�
		{
			if (fname == name && pwd == fpsw)
			{
				cout << "����Ա��֤��½�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managermenu(person);
				return;
			}
		}
	}
	
	cout << "��֤��¼ʧ��!" << endl;
	system("pause");
	system("cls");

}
void main_menu()//��ҳ��˵�
{
	cout << "-------------------------------��ӭ������ֻ���ͻ���ԤԼϵͳ-------------------------------" << endl;
	cout << endl;
	cout << "�������������" << endl;
	cout << "                -----------------------------------------" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             1��ѧ������                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             2����    ʦ                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             3���� �� Ա                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             0����    ��                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "                -----------------------------------------" << endl;
	cout << endl;
}
void exit_main()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}
int main()
{
	int choose;//��ҳ��ѡ��

	while (true)
	{
		main_menu();
		cout << "���������ѡ��" << endl;
		cin >> choose;

		switch (choose)
		{
		case 1://ѧ�����
			login(STUDENT_FILE, 1);
			break;
		case 2://��ʦ���
			login(TEACHER_FILE, 2);
			break;
		case 3://����Ա���
			login(ADMIN_FILE, 3);
			break;
		case 0://�˳�
			exit_main();
			break;
		default:
		{
			cout << "��������Ч���֣� " << endl;
			system("pause");
			system("cls");
		}
		break;
		}
	}
	return 0;
}