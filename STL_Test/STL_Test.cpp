#include<iostream>

#include "GenericProgramming_Test.h"
#include "array_source_code.h"
#include "deque_source_code.h"
#include "rb_tree_source_code.h"

using std::cout;
using std::endl;

int main()
{
	//test_unordered_multiset(1000000);

	//使用模板类
	/*
	GenericProgramming_Test<Stone> stoneCompare;
	Stone s1(100);
	Stone s2(200);
	
	cout<<"s1和s2中最小的石头为"<< stoneCompare.min(s1, s2).grass<<"吨";

	*/
	cout << "Custom::rb_tree 's size:" << sizeof(CustomSTL::rb_tree<int,int,int,int>) << endl;
	CustomSTL::G4_9::array<int, 6> myArray;
	auto begin = myArray.begin();
	auto end = myArray.end();
	for (int index = 0; index < myArray.size(); index++)
		myArray[index] = index;
	cout << "myArray数据呈现：";
	for (int index = 0; index < myArray.size(); index++)
		cout << myArray.at(index) << " ";

	cout << endl;
	cout <<"myArray的首地址<begin()> ："<< begin << endl;
	cout << "myArray的首地址<end()> ：" << end << endl;
	cout << "myArray容量：" << end - begin << endl;

}