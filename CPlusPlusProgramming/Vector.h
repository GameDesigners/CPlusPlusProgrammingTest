#pragma once
#include<iostream>
#include "Container.h"

template<typename T=double>
class Vector
{
private:
	T* elem;
	int count;
public:
	Vector(std::initializer_list<T>);  //使用一个列表进行初始化
	Vector(int c);
	Vector(const Vector<T>& a);            //拷贝构造函数
	Vector& operator=(const Vector<T>& a); //拷贝构造运算符

	//Vector(Vector&& a) : elem(a.elem), count(a.count)  { a.elem = nullptr; a.count = 0; }  //从a中“夺取元素”
	//Vector<T>& operator=(const Vector<T>&& a);
	
	T* data() { return elem; }
	int size() const { return count; };
};

//template<typename T=double>
//class Vector_container : public Container
//{
//private:
//	Vector<T> v;
//
//public:
//	Vector_container(int s) : v(s) {}
//	~Vector_container() {}
//
//	double& operator[](int i) { return v.data()[i]; }
//	int size() const { return v.size(); }
//};
