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
	myThreads.push_back(move(t));  //把t移动到myThreads中
	Vector<int> vec(n);

	if (vec.data() == nullptr) 
		cout << "new的类实例为空指针" << endl;

	for (int i = 0; i < vec.size(); ++i)
		vec.data()[i] = 777;

	return vec;  //把vec移动到init()之外，事实上函数的返回值就是右值引用
}


template<typename Container,typename Value>
Value sum(Container& c, Value v)
{
	for (int index = 0; index < c.size(); index++)
		v += c.data()[index];
	return v;
}

//constexpr ：返回的值是一个常量表达式
//const     ：参数的const表示在函数中不能修改参数的值
constexpr double square(const double& val)
{
	return val * val;
}

int main()
{
	cout << "Hello World" << endl;
	const int const_val = 1;                            //const_val是一个命名的常量
	constexpr double constexpr_val = 1.4 * square(17);  //constexpr_val常量表达式

	
	Vector<int> v = init(4);
	for (int index = 0; index < v.size(); ++index)
		cout << v.data()[index] << " ";

	int sum_value = sum(v, 0);
	cout << "v元素的和sum=" << sum_value << endl;


	cout << endl << endl << endl;
	Less_than<int> Iti{ 42 };  //Iti(i)将使用<比较i和42（i<42）的大小

	cout << "30用Iti比较器进行比较结果为：" << Iti(30) << endl;

	f(1, 1.2, "XiaoMi", "LeiJun", 2011);

	//自定义输出流
	CustomIOStreamTestEntry entry{ "LeiJun",12345678 };
	cout <<endl<< entry << endl;

	STLContainer_Vec<int> customVecs{ 1, 2, 3, 4, 5 };
	cout << customVecs[5] << endl;
}