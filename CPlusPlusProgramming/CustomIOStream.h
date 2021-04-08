#pragma once
#include<string>
#include<iostream>
#include<xiosbase>
class CustomIOStreamTestEntry
{
public:
	std::string name;
	int number = 0;
	CustomIOStreamTestEntry() {}
	CustomIOStreamTestEntry(std::string _name, int _number) : name(_name), number(_number) {}
};

/// <summary>
/// 自定义输出流函数
/// </summary>
/// <param name="os"></param>
/// <param name="e"></param>
/// <returns></returns>
std::ostream& operator<<(std::ostream& os, const CustomIOStreamTestEntry& e) {
	return os << "[\"" << e.name << "\"" << e.number << "]";
}


/// <summary>
/// 自定义输入流函数
/// </summary>
/// <param name="is"></param>
/// <param name="e"></param>
/// <returns></returns>
std::istream& operator>>(std::istream& is, CustomIOStreamTestEntry& e) {
	char c, c2;
	if (is >> c && c == '{' && is >> c2 && c2 == ' ') {
		std::string name;
		while (is.get(c) && c != ' ')
			name += c;

		if (is >> c && c == ',')
		{
			int number = 0;
			if (is >> number >> c && c == '}') {
				e = { name,number };
				return is;
			}
		}
	}
	is.setf(std::ios_base::failbit);  //将流状态设置为fail
	return is;
}


