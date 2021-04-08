#pragma once
#include <iostream>

/// <summary>
/// �ɱ�����б�ģ��ִ�к���
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="x"></param>
template<typename T>
void g(T x)
{
	std::cout << x << "  ";
}

//�ɱ�����б�ݹ���������õ��޲κ���
void f() {}

/// <summary>
/// �ɱ����ģ��
/// </summary>
/// <typeparam name="T">��һ�������Ĳ�������</typeparam>
/// <typeparam name="...Tail">�ɱ�����б�</typeparam>
/// <param name="head">��һ�������Ĳ�������</param>
/// <param name="...tail">����һ����Ĳ����б�</param>
template<typename T,typename... Tail>
void f(T head, Tail... tail)
{
	g(head);
	f(tail...);  //�ݹ麯��
}



