#include "manage.h"
#include "settingfile.h"
#include <algorithm>
#include <string>
//默认构造
Manager::Manager()
{

}

//有参构造
Manager::Manager(string name, string psw)
{
	//初始化信息
	this->name = name;
	this->password = psw;
	initvector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	Computerroom com;
	while (ifs >> com.c_id && ifs >> com.c_maxnum)
	{
		vc.push_back(com);
	}
	ifs.close();
	cout << "机房数量为:" << vc.size() << endl;
}

//菜单
void Manager::openmenu()
{
	cout << "-------------------------------欢迎来到船只博客机房预约系统-------------------------------" << endl;
	cout << endl;
	cout << "欢迎管理员" << this->name << "登录" << endl;
	cout << "                -----------------------------------------" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             1、添加账号                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             2、查看账号                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             3、查看机房信息             |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             4、清空预约记录             |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             0、注销登录                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "                -----------------------------------------" << endl;
	cout << endl;
 }

//添加账号
void Manager::addperson()
{
	cout << "请输入你要添加的类型:" << endl;
	cout << "1、学生" << endl;
	cout << "2、老师" << endl;
	string filename;//操作文件名
	string tip;//提示ID号
	string errortip;
	ofstream ofs;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		filename = STUDENT_FILE;
		tip = "请输入学号:";
		errortip = "学号重复，请重新输入:";
	}
	else if (select == 2)
	{
		filename = TEACHER_FILE;
		tip = "请输入职工编号:";
		errortip = "职工号重复，请重新输入:";
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
	
	cout << "请输入姓名:" << endl;
	cin >> name;
	cout << "请输入登陆密码:" << endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << endl;
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
	ofs.close();
	this->initvector();
}


void printvs(Student&s)
{
	cout << "学号:" << s.s_id << " 姓名:" << s.name << " 密码:" << s.password << endl;
}
void printvt(Teacher& s)
{
	cout << "职工号:" << s.m_empid << " 姓名:" << s.name << " 密码:" << s.password << endl;
}
//查看账号
void Manager::showperson()
{
	cout << "请选择查看的内容" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;
	int select;
	cin >> select;
	if (select == 1)		
	{
		//查看学生
		cout << "所有学生信息如下:" << endl;
		for_each(vs.begin(), vs.end(), printvs);
	}
	else
	{
		cout << "所有老师信息如下:" << endl;
		for_each(vt.begin(), vt.end(), printvt);
		//查看老师
	}
	system("pause");
	system("cls");
}

void printvc(Computerroom & c)
{
	cout << "机房ID："<< c.c_id << " 机房容量:" << c.c_maxnum << endl;
}
//查看机房信息
void Manager::showcomputer()
{
	cout << "机房信息如下:" << endl;
	for_each(vc.begin(), vc.end(), printvc);
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanfile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "清空成功!" << endl;
	system("pause");
	system("cls");
}

//初始化容器
void Manager::initvector()
{
	//确保文件为空
	vs.clear();
	vt.clear();

	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	Student s;

	while (ifs >> s.s_id && ifs >> s.name && ifs >> s.password)
	{
		vs.push_back(s);
	}
	cout << "当前学生数量为" << vs.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_empid && ifs >>t.name &&ifs>>t.password)
	{
		vt.push_back(t);
	}
	cout << "当前老师数量为" << vt.size() << endl;
	ifs.close();
}

//检测重复
bool Manager::checkrepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
		for (vector<Student>::iterator it = vs.begin(); it != vs.end(); it++)
		{
			if (id == it->s_id)
				return true;
		}
	}
	else
	{
		//检测老师
		for (vector<Teacher>::iterator it = vt.begin(); it != vt.end(); it++)
		{
			if (id == it->m_empid)
				return true;
		}
	}
	return false;
}
