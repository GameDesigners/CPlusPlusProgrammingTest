#pragma once
/// <summary>
/// ������
/// </summary>
class Container
{
public:
	virtual double& operator[](int) = 0;  //���麯��
	virtual int size() const = 0;         //������Ա����
	virtual ~Container(){}                //��������
};

