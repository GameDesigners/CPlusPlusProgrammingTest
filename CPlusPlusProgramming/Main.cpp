#include <iostream>
#include <cmath>
#include<vector>
#include <thread>
#include "Vector.cpp"
#include "Less_than.h"
#include "VariadicTemplate.h"
#include "CustomIOStream.h"
#include "STLContainer.h"

using namespace std;

enum class Color{red,green};
enum class PenColor{red,green};

std::vector<thread> myThreads;
Vector<int> init(int n)
{
	thread t;
	myThreads.push_back(move(t));  //��t�ƶ���myThreads��
	Vector<int> vec(n);

	if (vec.data() == nullptr) 
		cout << "new����ʵ��Ϊ��ָ��" << endl;

	for (int i = 0; i < vec.size(); ++i)
		vec.data()[i] = 777;

	return vec;  //��vec�ƶ���init()֮�⣬��ʵ�Ϻ����ķ���ֵ������ֵ����
}


template<typename Container,typename Value>
Value sum(Container& c, Value v)
{
	for (int index = 0; index < c.size(); index++)
		v += c.data()[index];
	return v;
}

//constexpr �����ص�ֵ��һ���������ʽ
//const     ��������const��ʾ�ں����в����޸Ĳ�����ֵ
constexpr double square(const double& val)
{
	return val * val;
}

int main()
{
	cout << "Hello World" << endl;
	const int const_val = 1;                            //const_val��һ�������ĳ���
	constexpr double constexpr_val = 1.4 * square(17);  //constexpr_val�������ʽ

	
	Vector<int> v = init(4);
	for (int index = 0; index < v.size(); ++index)
		cout << v.data()[index] << " ";

	int sum_value = sum(v, 0);
	cout << "vԪ�صĺ�sum=" << sum_value << endl;


	cout << endl << endl << endl;
	Less_than<int> Iti{ 42 };  //Iti(i)��ʹ��<�Ƚ�i��42��i<42���Ĵ�С

	cout << "30��Iti�Ƚ������бȽϽ��Ϊ��" << Iti(30) << endl;

	f(1, 1.2, "XiaoMi", "LeiJun", 2011);

	//�Զ��������
	CustomIOStreamTestEntry entry{ "LeiJun",12345678 };
	cout <<endl<< entry << endl;

	STLContainer_Vec<int> customVecs{ 1, 2, 3, 4, 5 };
	cout << customVecs[5] << endl;
}