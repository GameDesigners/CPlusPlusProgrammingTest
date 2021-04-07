#include <iostream>
#include <cmath>
#include<vector>
#include <thread>
#include "Vector.cpp"
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

//constexpr �����ص�ֵ��һ���������ʽ
//const     ��������const��ʾ�ں����в����޸Ĳ�����ֵ
constexpr double square(const double& val)
{
	return val * val;
}
void heartbeat() {}
int main()
{
	cout << "Hello World" << endl;


	const int const_val = 1;                            //const_val��һ�������ĳ���
	constexpr double constexpr_val = 1.4 * square(17);  //constexpr_val�������ʽ

	
	Vector<int> v = init(4);
	for (int index = 0; index < v.size(); ++index)
		cout << v.data()[index] << " ";
}