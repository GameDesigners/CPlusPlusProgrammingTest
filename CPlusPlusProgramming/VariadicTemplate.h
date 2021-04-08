#pragma once
#include <iostream>

/// <summary>
/// 可变参数列表模板执行函数
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="x"></param>
template<typename T>
void g(T x)
{
	std::cout << x << "  ";
}

//可变参数列表递归完后最后调用的无参函数
void f() {}

/// <summary>
/// 可变参数模板
/// </summary>
/// <typeparam name="T">第一个参数的参数类型</typeparam>
/// <typeparam name="...Tail">可变参数列表</typeparam>
/// <param name="head">第一个参数的参数变量</param>
/// <param name="...tail">除第一个外的参数列表</param>
template<typename T,typename... Tail>
void f(T head, Tail... tail)
{
	g(head);
	f(tail...);  //递归函数
}



