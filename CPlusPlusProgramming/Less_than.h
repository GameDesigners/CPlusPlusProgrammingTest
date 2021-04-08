#pragma once
/// <summary>
/// º¯Êı¶ÔÏó
/// </summary>
/// <typeparam name="T"></typeparam>
template<typename T> class Less_than
{
private:
	const T val;
public:
	Less_than(const T& v) : val(v) {}
	bool operator()(const T& x) const { return x < val; }
};

