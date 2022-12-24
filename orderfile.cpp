#include "orderfile.h"
#include <iostream>
#include <string>
//构造函数
Orderfile::Orderfile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;
	string interval;//时间段
	string id;
	string room;
	string name;
	string status;//状态

	this->m_size = 0;//条数
	while (ifs >> date && ifs >> id && ifs >> interval && ifs >> name && ifs >> room && ifs >> status)
	{
		//cout << date << " "  << interval << " " << id << " " << room << " " << name << " " << status <<" " << endl;
		string key;
		string value;
		map<string, string>m;
		int start=0;
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(start, pos);
			value = date.substr(pos + 1, date.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = id.find(":");
		if (pos != -1)
		{
			key = id.substr(start, pos);
			value = id.substr(pos + 1, id.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(start, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		
		pos = name.find(":");
		if (pos != -1)
		{
			key = name.substr(start, pos);
			value = name.substr(pos + 1, name.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = room.find(":");
		if (pos != -1)
		{
			key = room.substr(start, pos);
			value = room.substr(pos + 1, room.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(start, pos);
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		this->mdata.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
	ifs.close();
	/*for (map<int, map<string, string>>::iterator it = this->mdata.begin(); it != this->mdata.end(); it++)
	{
		cout << "条数为==" << it->first << " value==" << endl;
		for (map<string, string>::iterator iit = (*it).second.begin(); iit != (*it).second.end(); iit++)
		{
			cout << "key == " << iit->first << " value ==" << iit->second << " ";
		}
		cout << endl;
	}*/
}

//更新预约记录
void Orderfile::updateorder()
{
	if (this->m_size == 0)
		return;
	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_size; i++)
	{
		ofs << "date:" << this->mdata[i]["date"] << " ";
		ofs << "id:" << this->mdata[i]["id"] << " ";
		ofs << "interval:" << this->mdata[i]["interval"] << " ";
		ofs << "name:" << this->mdata[i]["name"] << " ";
		ofs << "room:" << this->mdata[i]["room"] << " ";
		ofs << "status:" << this->mdata[i]["status"] << endl;
	}
	ofs.close();
}