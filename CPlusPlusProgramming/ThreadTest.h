#pragma once
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex m;  //控制共享数据访问的mutex
int sh;        //共享的数据

void thread_f(const std::vector<double>& v) {
	for (size_t index = 0; index < v.size(); index++)
		std::cout << "这是在某个线程执行的任务1  value[" << index << "]=" << v[index] << std::endl;
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
	std::unique_lock<std::mutex> lck{ m };  //获取mutex
	sh += 7;                                //处理共享数据
	//隐式释放mutex
}

struct  F
{
	std::vector<double>& v;
	F(std::vector<double>& vv) : v{ vv } {}

	void operator()() {
		for (size_t index = 0; index < v.size(); index++)
			std::cout << "这是在某个线程执行的任务2  value[" << index << "]=" << v[index] << std::endl;
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

	t1.join();  //等待线程t1完成
	t2.join();  //等待线程t2完成
	t3.join();  //等待线程t3完成

	std::cout << "容器vec2中元素的和为：" << result << std::endl;
	
	std::cout << "完成线程工作并退出此函数" << std::endl;
}