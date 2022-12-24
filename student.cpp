#include "student.h"
#include <string>
#include <fstream>
#include "settingfile.h"
#include <vector>
//有参构造
Student::Student(int id, string name, string pwd)
{
	//初始化信息
	this->name = name;
	this->s_id = id;
	this->password = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		return;
	}

	Computerroom p;
	while (ifs >> p.c_id && ifs >> p.c_maxnum)
	{

		vc.push_back(p);
	}
	ifs.close();

}

//默认构造
Student::Student()
{

}

//菜单界面
void Student::openmenu()
{
	cout << "-------------------------------欢迎来到船只博客机房预约系统-------------------------------" << endl;
	cout << endl;
	cout << "欢迎学生代表" << this->name << "登录"<< endl;
	cout << "                -----------------------------------------" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             1、申请预约                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             2、查看自身预约             |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             3、查看所有人预约           |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             4、取消预约                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             0、注销登录                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "                -----------------------------------------" << endl;
	cout << endl;
}

//申请预约
void Student::applyorder()
{
	cout << "机房开放时间为周一至周五" << endl;
	cout << "请输入申请预约的时间:" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;
	int date;
	int interval;//时间段
	int room;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
			break;
		else
			cout << "输入有误请重新输入" << endl;
	}
	cout << "请输入申请预约的时间段:" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
			break;
		else
			cout << "输入有误请重新输入" << endl;
	}
	cout << "请选择机房:" << endl;
	cout << vc[0].c_id << "号机房容量为:" << vc[0].c_maxnum << endl;
	cout << vc[1].c_id << "号机房容量为:" << vc[1].c_maxnum << endl;
	cout << vc[2].c_id << "号机房容量为:" << vc[2].c_maxnum << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
			break;
		else
			cout << "输入有误请重新输入" << endl;
	}
	cout << "预约成功，审核中!" << endl;
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

//查看我的预约
void Student::showmyorder()
{
	Orderfile o;
	if (o.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < o.m_size; i++)
	{
		//.c_str转c风格字符串 atoi转int
		if (this->s_id == atoi(o.mdata[i]["id"].c_str()))//找到自身预约
		{
			cout << "预约日期:周" << o.mdata[i]["date"];
			cout << " 时间段:" << (o.mdata[i]["interval"] == "1" ? "上午": "下午");
			cout << " 机房编号" << o.mdata[i]["room"];
			string status=" 状态";
			if (o.mdata[i]["status"] == "1")
			{
				status += "审核中";
			}
			else if (o.mdata[i]["status"] == "2")
			{
				status += "预约成功";
			}
			else if (o.mdata[i]["status"] == "-1")
			{
				status += "审核不通过";
			}
			else
			{
				status += "预约已经取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
		
}

//查看所有预约
void Student::showallorder()
{
	Orderfile o;
	if (o.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < o.m_size; i++)
	{
		cout << i+1 <<"、";
		cout << " 预约日期:周" << o.mdata[i]["date"];
		cout << " 时间段:" << (o.mdata[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 学号" << o.mdata[i]["id"];
		cout << " 机房编号" << o.mdata[i]["room"];
		string status = " 状态";
		if (o.mdata[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (o.mdata[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (o.mdata[i]["status"] == "-1")
		{
			status += "审核不通过";
		}
		else
		{
			status += "预约已经取消";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");

}

//取消预约
void Student::cancelorder()
{
	Orderfile o;
	if (o.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录可以取消，请输入需要取消的记录:" << endl;
	vector<int>v;
	int index = 1;
	for (int i = 0; i < o.m_size; i++)
	{
		if (atoi(o.mdata[i]["id"].c_str()) == this->s_id)
		{
			if (o.mdata[i]["status"] == "1" || o.mdata[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "、";
				cout << "预约日期:周" << o.mdata[i]["date"];
				cout << " 时间段:" << (o.mdata[i]["interval"] == "1" ? "上午" : "下午");
				cout << " 机房编号" << o.mdata[i]["room"];
				string status = " 状态";
				if (o.mdata[i]["status"] == "1")
				{
					status += "审核中";
				}
				else if (o.mdata[i]["status"] == "2")
				{
					status += "预约成功";
				}
				cout << status << endl;
			}
		}
	}
	cout << "请输入需要取消的记录,0代表返回" << endl;
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
				cout << "已取消预约！" << endl;
				break;
			}
		}
		else
		{
			cout << "请输入正确的数字:" << endl;
		}
			
	}
	system("pause");
	system("cls");
	
}
