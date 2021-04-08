#pragma once
#ifndef STL_COMMONTOOL
#define STL_COMMONTOOL

#include <utility>

template<typename T1,typename T2>
std::ostream& operator <<(std::ostream& strm, const std::pair<T1, T2>& p)
{
	return strm << "[" << p.first << "," << p.second << "]";
}

#endif // !STL_COMMONTOOL

