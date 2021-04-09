#pragma once
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex m;  //���ƹ������ݷ��ʵ�mutex
int sh;        //���������

void thread_f(const std::vector<double>& v) {
	for (size_t index = 0; index < v.size(); index++)
		std::cout << "������ĳ���߳�ִ�е�����1  value[" << index << "]=" << v[index] << std::endl;
}

void thread_f_sum(const std::vector<double>& v, double* res) {
	if (res != nullptr)
	{
		*res = 0;
		for (size_t index = 0; index < v.size(); index++)
			*res += v[index];
	}
}

void thread_f_sharedValue() {
	std::unique_lock<std::mutex> lck{ m };  //��ȡmutex
	sh += 7;                                //����������
	//��ʽ�ͷ�mutex
}

struct  F
{
	std::vector<double>& v;
	F(std::vector<double>& vv) : v{ vv } {}

	void operator()() {
		for (size_t index = 0; index < v.size(); index++)
			std::cout << "������ĳ���߳�ִ�е�����2  value[" << index << "]=" << v[index] << std::endl;
	}
};


void user_useThread()
{
	std::vector<double> some_vec = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<double> vec2 = { 11,12,13,14,15,16,17,18,19,20 };
	std::thread t1( thread_f,some_vec );
	std::thread t2{ F(vec2) };
	double result=0;
	double *sum_result=&result;
	std::thread t3{ thread_f_sum,vec2,sum_result };

	t1.join();  //�ȴ��߳�t1���
	t2.join();  //�ȴ��߳�t2���
	t3.join();  //�ȴ��߳�t3���

	std::cout << "����vec2��Ԫ�صĺ�Ϊ��" << result << std::endl;
	
	std::cout << "����̹߳������˳��˺���" << std::endl;
}