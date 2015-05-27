/*       宁夏数据采集程序
 *1、节点类Bus，当需要的数据发生改变时：
 *2、支路类Branch	
 *3、机组类Unit		
 *4、负荷类Load
 *5、风电场类WindFarm
 */
#ifndef DATA
#define DATA

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Bus{
public:
	Bus(int code=-1,string name=""):busCode(code),busName(name){}
	void setBusCode(int);
	void setBusName(string);
	bool isValid();
	
	int getBusCode()const{return busCode;}//后面const的必要性
	string getBusName()const{return busName;}
	
	// bool operator==(const Bus&);
	friend bool operator==(const Bus&,const Bus&);
	friend ostream& operator<<(ostream& ,Bus&);
	
private:
	int busCode;//节点编号
	string busName;//节点名称
};

class Branch{
};

class Unit{
};

class Load{
};

class WindFarm{
};





//全局函数统一放到最后
vector<string> split(string str);
Bus createBus(int ,string );
void getData(ifstream& ,vector<Bus>& );

#endif //DATA