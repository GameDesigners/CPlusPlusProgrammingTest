#include "Vector.h"

template<typename T>
Vector<T>::Vector(std::initializer_list<T> l) {
	count = sizeof(l) / sizeof(int);
	elem = new T[count];
}

template<typename T>
Vector<T>::Vector(int c) {
	count = c;
	elem = new T[c];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& a){
	/*
	    重新分配空间的做法
    */
	count = a.size();
	elem = new T[count];

	for (int index = 0; index != count; index++)
		elem[index] = a.elem[index];
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a) {
	count = a.size();
	double* p = new T[count];
	for (size_t i = 0; i!= count; i++)
		p[i] = a.elem[i];

	delete[] elem;  //删除旧元素
	elem = p;
	return *this;
}
