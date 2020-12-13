#pragma once
#ifndef GenericProgramming_Test_H
#define GenericProgramming_Test_H

template <typename T> class GenericProgramming_Test
{
public:
	inline const T& min(const T& a, const T& b)
	{
		return a > b ? b : a;
	}
};

class Stone
{
public:
	double grass;

public:
	Stone(double _grass) : grass(_grass) {}

	inline bool operator >(const Stone& stone) const
	{
		return grass > stone.grass;
	}
};
#endif // !GenericProgramming_Test_H


