#pragma once
#include<iostream>
#include<chrono>
#include<random>
#include<functional>
#include<vector>

void use_clock()
{
	std::cout << "��ʼ��ʱ��" << std::endl;
	auto t0 = std::chrono::high_resolution_clock::now();
	for (size_t i = 0; i < 1000; i++)
		std::cout << "in the loop..." << std::endl;
	auto t1 = std::chrono::high_resolution_clock::now();

	std::cout << "�˺������ˣ�" << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() << "΢��" << std::endl;
}


void use_random_engine() {
	using my_engine = std::default_random_engine;            //��������
	using my_distribution = std::uniform_int_distribution<>; //�ֲ�����

	my_engine re{};                     //Ĭ������
	my_distribution one_to_six{ 1,6 };  //�÷ֲ������ֵӳ�䵽1��~6�ķ�Χ
	auto die = std::bind(one_to_six,re);

	std::cout << "�ֲ������[1,6]�õ���ֵΪ" << (int)die() << std::endl;
}


class Random_int
{
public:
	Random_int(int low, int high) :dist{ low,high } {}
	int operator()() { return dist(re); }

private:
	std::default_random_engine re;
	std::uniform_int_distribution<> dist;
};

void use_Random_int_DrawHistogram(int low,int high)
{
	Random_int rnd{ low,high };
	std::vector<int> histogram(high+1);
	for (int i = 0; i != 200; ++i)
		++histogram[rnd()];

	for (int i = low; i < high; i++)
	{
		std::cout << i << " ";
		for (int j = 0; j < histogram[i]; ++j) 
			std::cout << "*";
		std::cout << std::endl;
	}
}

template<typename T>
class Value {
public :
	using value_type = T;
	value_type val;
	Value() {}
	Value(T t) : val(t) {}
};

template<class U1, class U2>
auto operator+(Value<U1>& a, Value<U2>& b)->Value<decltype(U1{} + U2{}) >
{
	Value<decltype(U1{} + U2{}) > res;
	res.val= a.val + b.val;
	return res;
}

//decltype��ʹ��
template<typename T1,typename T2>
auto Sum(T1 v1, T2 v2)
{
	return v1 + v2;
}