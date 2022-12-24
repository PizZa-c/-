#include "teacher.h"
#include "orderfile.h"
#include <vector>
//默认构造
Teacher::Teacher()
{

}

//有参构造
Teacher::Teacher(int id, string name,  string psw)
{
	this->m_empid = id;
	this->name = name;
	this->password = psw;
}

//菜单
void Teacher::openmenu()
{
	cout << endl;
	cout << "欢迎老师" << this->name << "登录" << endl;
	cout << "                -----------------------------------------" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             1、查看所有人预约           |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             2、审核预约                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |             0、注销登录                 |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "               |                                         |" << endl;
	cout << "                -----------------------------------------" << endl;
	cout << endl;
}

//查看所有预约
void Teacher::showallorder()
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
		cout << i + 1 << "、";
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

//审核预约
void Teacher::validorder()
{
	Orderfile o;
	if (o.m_size == 0) {
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下" << endl;
	vector<int>v;
	int index = 0;
	for (int i = 0; i < o.mdata.size(); i++)
	{
		if (o.mdata[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、" << "预约日期:周" << o.mdata[i]["date"];
			cout << " 时间段：" << (o.mdata[i]["interval"] == "1" ? "上午" : "下午");
			cout << " 学生编号:" << o.mdata[i]["id"];
			cout << " 机房编号:" << o.mdata[i]["room"];
			cout << "状态: 审核中" << endl;
		}
	}
	cout << "请输入审核的预约记录，0代表返回" << endl;
	int select = 0;//接受用户选择的预约记录
	int ret = 0;//接受预约的结果的记录

	while (true)
	{
		cin >> select;
		if (select >= 0)
		{
			if (select == 0)
				break;
			cout << "请输入审核结果:" << endl;
			cout << "1、通过" << endl;
			cout << "2、不通过" << endl;
			cin >> ret;
			if (ret == 1)
			{
				//通过情况
				o.mdata[v[select-1]]["status"] = "2";
			}
			else
			{
				o.mdata[v[select - 1]]["status"] = "-1";
				//不通过
			}
			o.updateorder();//更新预约记录
			cout << "审核完毕" << endl;
			break;
		}
		
		else
		{
			cout << "请输入有效数字:" << endl;
		}
	}
	system("pause");
	system("cls");
}

