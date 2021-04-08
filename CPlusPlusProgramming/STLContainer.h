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
	*   使用at会抛出一个类型为out_of_range异常
	*   可以用try...catch捕捉到
	*/
	T& operator[](int i) {
		try {
			return std::vector<T>::at(i);
		}
		catch(std::exception& e){
			std::cerr << e.what();
		}
	}

	const T& operator[](int i) const {  //常量版本
		try {
			return std::vector<T>::at(i);
		}
		catch (std::exception& e) {
			std::cerr << e.what();
		}
	}
};

