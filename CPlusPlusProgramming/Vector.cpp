#include "Vector.h"

template<typename value_type>
Vector<value_type>::Vector(std::initializer_list<value_type> l) {
	count = sizeof(l) / sizeof(int);
	elem = new value_type[count];
}

template<typename value_type>
Vector<value_type>::Vector(int c) {
	count = c;
	elem = new value_type[c];
}

template<typename value_type>
Vector<value_type>::Vector(const Vector<value_type>& a){
	/*
	    重新分配空间的做法
    */
	count = a.size();
	elem = new value_type[count];

	for (int index = 0; index != count; index++)
		elem[index] = a.elem[index];
}

template<typename value_type>
Vector<value_type>& Vector<value_type>::operator=(const Vector<value_type>& a) {
	count = a.size();
	double* p = new value_type[count];
	for (size_t i = 0; i!= count; i++)
		p[i] = a.elem[i];

	delete[] elem;  //删除旧元素
	elem = p;
	return *this;
}
