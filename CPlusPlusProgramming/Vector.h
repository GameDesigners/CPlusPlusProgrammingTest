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
	Vector(std::initializer_list<T>);  //ʹ��һ���б���г�ʼ��
	Vector(int c);
	Vector(const Vector<T>& a);            //�������캯��
	Vector& operator=(const Vector<T>& a); //�������������

	//Vector(Vector&& a) : elem(a.elem), count(a.count)  { a.elem = nullptr; a.count = 0; }  //��a�С���ȡԪ�ء�
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
