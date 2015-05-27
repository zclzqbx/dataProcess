#include "data.h"
#include <fstream>

using namespace std;

ifstream input("nx_20150427_1355.txt",ios::in);
//指明数据所在位置
ofstream output("data.txt",ios::ate);

int main()
{
	vector<Bus> busList;//存放了所有节点
	getData(input,busList);//读取所有信息函数
	
	for(size_t i=0;i<busList.size();++i)
	{
		output<<busList[i]<<endl;
	}

	input.close();
	output.close();
	return 0;
}