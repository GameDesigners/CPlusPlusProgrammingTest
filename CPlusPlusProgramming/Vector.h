#pragma once
#include<iostream>
#include "Container.h"

template<typename T=double>
class Vector
{
private:
	using value_type = T;  //����
	value_type* elem;
	int count;
public:
	Vector(std::initializer_list<value_type>);  //ʹ��һ���б���г�ʼ��
	Vector(int c);
	Vector(const Vector<value_type>& a);            //�������캯��
	Vector& operator=(const Vector<value_type>& a); //�������������

	//Vector(Vector&& a) : elem(a.elem), count(a.count)  { a.elem = nullptr; a.count = 0; }  //��a�С���ȡԪ�ء�
	//Vector<T>& operator=(const Vector<T>&& a);
	
	value_type* data() { return elem; }
	int size() const { return count; };

	value_type* begin(Vector<value_type>& x) { return &x.data()[0]; }
	value_type* end(Vector<value_type>& x) { return x.begin() + x.count; }
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
