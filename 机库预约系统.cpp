#include <iostream>
using namespace std;
#include "identity.h"
#include <fstream>
#include "settingfile.h"
#include "student.h"
#include "teacher.h"
#include "manage.h"
//进入学生子菜单界面
void studentmenu(Identity*& student)
{

	while (true)
	{
		student->openmenu();

		//将父类指针转为子类指针可以调用子类其他接口
		Student* stu = (Student*)student;
		//student->openmenu();
		int select = 0;
		cout << "请输入你的选择：" << endl;
		cin >> select;
		if (select == 1)
		{
			//申请预约
			stu->applyorder();
		}
		else if (select == 2)
		{
			//查看我的预约
			stu->showmyorder();
		}
		else if (select == 3)
		{
			//查看所有人的预约
			stu->showallorder();
		}
		else if (select == 4)
		{
			//取消预约
			stu->cancelorder();
		}
		else
		{
			//cout << "注销登录"<< endl;
			delete stu;
			system("pause");
			system("cls");
			return;
		}
	}
}

//进入管理员子菜单界面
void managermenu(Identity* &manager)
{
	while (true)
	{
		manager->openmenu();
		
		//将父类指针转为子类指针可以调用子类其他接口
		Manager* man = (Manager*)manager;
		//man->openmenu();
		int select = 0;
		cout << "请输入你的选择：" << endl;
		cin >> select;
		if (select == 1)
		{
			//cout << "添加账号" << endl;
			man->addperson();
		}
		else if (select == 2)
		{
			//cout << "查看账号" << endl;
			man->showperson();
		}
		else if (select == 3)
		{
			//cout << "查看机房信息" << endl;
			man->showcomputer();
		}
		else if (select == 4)
		{
			//cout << "清空预约记录" << endl;
			man->cleanfile();
		}
		else
		{
			//cout << "注销登录"<< endl;
			delete man;
			system("pause");
			system("cls");
			return;
		}
	}
}
//进入老师子菜单
void teachermenu(Identity* &teacher)
{
	while (true)
	{
		//调用子菜单界面
		teacher->openmenu();

		Teacher* tea = (Teacher*)teacher;
		cout << "请输入你要选择的操作:" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			//查看所有预约
			tea->showallorder();
		}
		else if (select == 2)
		{
			//审核预约
			tea->validorder();
		}
		else
		{
			delete tea;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return ;
		}
	}
}
//登录功能
void login(string filename, int type)
{
	//父类指针，用于操作子类对象
	Identity* person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(filename, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;

	if (type == 1)//学生
	{
		cout << "请输入你的学号:" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号:" << endl;
		cin >> id;
	}
	cout << "请输入用户名:" << endl;
	cin >> name;
	cout << "请输入密码: " << endl;
	cin >> pwd;
	if (type == 1)//学生
	{
		//成员信息
		int fid;
		string fname;
		string fpsw;
		while (ifs >> fid && ifs >> fname && ifs >> fpsw)
		{
			if (fid == id && fname == name && pwd == fpsw)
			{
				cout << "学生验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentmenu(person);
				return;
			}
		}
	}
	else if (type == 2)//老师
	{
		//成员信息
		int fid;
		string fname;
		string fpsw;
		while (ifs >> fid && ifs >> fname && ifs >> fpsw)//ifs>>不会读取空格
		{
			if (fid == id && fname == name && pwd == fpsw)
			{
				cout << "老师验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id,name,pwd);
				teachermenu(person);
				return;
			}
		}
	}
	else //管理员
	{
		//成员信息
		
		string fname;
		string fpsw;
		while (ifs >> fname && ifs >> fpsw)//ifs>>不会读取空格
		{
			if (fname == name && pwd == fpsw)
			{
				cout << "管理员验证登陆成功" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managermenu(person);
				return;
			}
		}
	}
	
	cout << "验证登录失败!" << endl;
	system("pause");
	system("cls");

}
void main_menu()//主页面菜单
{
	cout << "-------------------------------欢迎来到船只博客机房预约系统-------------------------------" << endl;
	cout << endl;
	cout << "请输入您的身份" << endl;
	cout << "                -----------------------------------------" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             1、学生代表                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             2、老    师                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             3、管 理 员                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             0、退    出                 |" << endl;
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
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}
int main()
{
	int choose;//主页面选择

	while (true)
	{
		main_menu();
		cout << "请输入你的选择：" << endl;
		cin >> choose;

		switch (choose)
		{
		case 1://学生身份
			login(STUDENT_FILE, 1);
			break;
		case 2://老师身份
			login(TEACHER_FILE, 2);
			break;
		case 3://管理员身份
			login(ADMIN_FILE, 3);
			break;
		case 0://退出
			exit_main();
			break;
		default:
		{
			cout << "请输入有效数字！ " << endl;
			system("pause");
			system("cls");
		}
		break;
		}
	}
	return 0;
}