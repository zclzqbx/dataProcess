#include "data.h"
#include <fstream>
#include <iostream>
using namespace std;

//Bus�ڵ�
void Bus::setBusCode(int code)//�޸Ľڵ���
{
	busCode=code;
}

void Bus::setBusName(string name)//�޸Ľڵ�����
{
	busName=name;
}

bool Bus::isValid()//�жϽڵ��Ƿ����
{
	if(busCode<0 || busName.size())
		return false;
	
	return true;
}

// bool Bus::operator==(const Bus& bus)//�ж��Ƿ����
// {
	// return (this->busName==bus.getBusName());
// }

bool operator==(const Bus& bus1,const Bus& bus2)
{
	return (bus1.getBusName()==bus2.getBusName());
}

ostream& operator<<(ostream& output,Bus& bus)//���
{
	output<<"�ڵ���:"<<bus.getBusCode()<<endl;
	output<<"�ڵ�����:"<<bus.getBusName()<<endl;
	return output;
}


//ȫ�ֺ���
vector<string> split(string str)//�ָ��ַ�������
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

Bus createBus(int code,string name)//�����½ڵ�
{
	Bus bus;
	bus.setBusCode(code);
	bus.setBusName(name);
	return bus;
}

void getData(ifstream& input,vector<Bus>& vecBus)//��ȡ���нڵ��������Ϣ����
{
	if(!input)
		return;
	string str;
	
	while(1)
	{
		str.clear();
		getline(input,str);
		if(str=="<Bus::nx type=ȫ��>")
		{
			int i=0;
			str.clear();
			getline(input,str);
			vector<string> vecHeader=split(str);
			
			int busNameColumn(0);//ʶ���ͷ
			for(size_t t=0;t<vecHeader.size();++t)
			{
				if(vecHeader[t]=="node")
				{
					busNameColumn=t;
					break;
				}
			}
			const int busNameColumnConst=busNameColumn;
			//��¼����Ҫ���е�λ��

			str.clear();//����һ�������ǲ���Ҫ�ģ������һ������
			getline(input,str);
			str.clear();
			getline(input,str);
			
			while(str!="</Bus::nx>")
			{
				vector<string> vec=split(str);
				//�������ݶ��Ѿ������vec�У���������ѡ����������
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