/*       �������ݲɼ�����
 *1���ڵ���Bus������Ҫ�����ݷ����ı�ʱ��
 *2��֧·��Branch	
 *3��������Unit		
 *4��������Load
 *5����糡��WindFarm
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
	
	int getBusCode()const{return busCode;}//����const�ı�Ҫ��
	string getBusName()const{return busName;}
	
	// bool operator==(const Bus&);
	friend bool operator==(const Bus&,const Bus&);
	friend ostream& operator<<(ostream& ,Bus&);
	
private:
	int busCode;//�ڵ���
	string busName;//�ڵ�����
};

class Branch{
};

class Unit{
};

class Load{
};

class WindFarm{
};





//ȫ�ֺ���ͳһ�ŵ����
vector<string> split(string str);
Bus createBus(int ,string );
void getData(ifstream& ,vector<Bus>& );

#endif //DATA