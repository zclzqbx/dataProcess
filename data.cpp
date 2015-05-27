#include "data.h"
#include <fstream>
#include <iostream>
using namespace std;

//Bus节点
void Bus::setBusCode(int code)//修改节点编号
{
	busCode=code;
}

void Bus::setBusName(string name)//修改节点名称
{
	busName=name;
}

bool Bus::isValid()//判断节点是否合理
{
	if(busCode<0 || busName.size())
		return false;
	
	return true;
}

// bool Bus::operator==(const Bus& bus)//判断是否相等
// {
	// return (this->busName==bus.getBusName());
// }

bool operator==(const Bus& bus1,const Bus& bus2)
{
	return (bus1.getBusName()==bus2.getBusName());
}

ostream& operator<<(ostream& output,Bus& bus)//输出
{
	output<<"节点编号:"<<bus.getBusCode()<<endl;
	output<<"节点名称:"<<bus.getBusName()<<endl;
	return output;
}


//全局函数
vector<string> split(string str)//分割字符串函数
{
	vector<string> vec;
	size_t i=0;
	string subStr;
	subStr.clear();
	while(i<str.size())
	{
		if(str[i]==' ')
		{
			if(!subStr.empty())
				vec.push_back(subStr);
			subStr.clear();
		}
		else
		{
			subStr+=str[i];
		}
		++i;
	}
	vec.push_back(subStr);
	return vec;
}

Bus createBus(int code,string name)//创新新节点
{
	Bus bus;
	bus.setBusCode(code);
	bus.setBusName(name);
	return bus;
}

void getData(ifstream& input,vector<Bus>& vecBus)//读取所有节点或其他信息函数
{
	if(!input)
		return;
	string str;
	
	while(1)
	{
		str.clear();
		getline(input,str);
		if(str=="<Bus::nx type=全数>")
		{
			int i=0;
			str.clear();
			getline(input,str);
			vector<string> vecHeader=split(str);
			
			int busNameColumn(0);//识别表头
			for(size_t t=0;t<vecHeader.size();++t)
			{
				if(vecHeader[t]=="node")
				{
					busNameColumn=t;
					break;
				}
			}
			const int busNameColumnConst=busNameColumn;
			//记录所需要行列的位置

			str.clear();//其中一行数据是不需要的，先清除一行数据
			getline(input,str);
			str.clear();
			getline(input,str);
			
			while(str!="</Bus::nx>")
			{
				vector<string> vec=split(str);
				//所有数据都已经存放在vec中，接下来是选出有用数据
				Bus bus=createBus(i,vec[busNameColumnConst]);
				size_t t=0;
				for(;t<vecBus.size();++t)
				{
					if(vecBus[t]==bus)
					{
						str.clear();
						getline(input,str);
						break;
					}
				}
				if(t<vecBus.size())continue;
				vecBus.push_back(bus);
				i++;
				str.clear();
				getline(input,str);
			}
		}
		if(str=="</Bus::nx>")
			break;
	}
}