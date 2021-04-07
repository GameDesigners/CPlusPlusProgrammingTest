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
	myThreads.push_back(move(t));  //把t移动到myThreads中
	Vector<int> vec(n);

	if (vec.data() == nullptr) 
		cout << "new的类实例为空指针" << endl;

	for (int i = 0; i < vec.size(); ++i)
		vec.data()[i] = 777;

	return vec;  //把vec移动到init()之外，事实上函数的返回值就是右值引用
}

//constexpr ：返回的值是一个常量表达式
//const     ：参数的const表示在函数中不能修改参数的值
constexpr double square(const double& val)
{
	return val * val;
}
void heartbeat() {}
int main()
{
	cout << "Hello World" << endl;


	const int const_val = 1;                            //const_val是一个命名的常量
	constexpr double constexpr_val = 1.4 * square(17);  //constexpr_val常量表达式

	
	Vector<int> v = init(4);
	for (int index = 0; index < v.size(); ++index)
		cout << v.data()[index] << " ";
}