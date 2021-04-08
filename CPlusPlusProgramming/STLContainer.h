#pragma once
#include<iostream>
#include<vector>
#include<exception>

template<typename T>
class STLContainer_Vec : public std::vector<T>
{
public:
	using std::vector<T>::vector;

	/*
	*   ʹ��at���׳�һ������Ϊout_of_range�쳣
	*   ������try...catch��׽��
	*/
	T& operator[](int i) {
		try {
			return std::vector<T>::at(i);
		}
		catch(std::exception& e){
			std::cerr << e.what();
		}
	}

	const T& operator[](int i) const {  //�����汾
		try {
			return std::vector<T>::at(i);
		}
		catch (std::exception& e) {
			std::cerr << e.what();
		}
	}
};

