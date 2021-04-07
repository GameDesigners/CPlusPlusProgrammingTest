#pragma once
/// <summary>
/// 抽象类
/// </summary>
class Container
{
public:
	virtual double& operator[](int) = 0;  //纯虚函数
	virtual int size() const = 0;         //常量成员函数
	virtual ~Container(){}                //析构函数
};

