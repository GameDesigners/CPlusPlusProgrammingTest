#pragma once
#include <iterator>
#include <xutility>

using std::iterator_traits;
using std::iterator;

template<typename _Iterator,typename _Container>
class __nomal_iterator
{
protected:
	_Iterator _M_current;
	typedef iterator_traits<_Iterator> __traits_type;

public:
	typedef _Iterator iterator_type;
	typedef typename __traits_type::iterator_category iterator_category;
	typedef typename __traits_type::value_type        value_type;
	typedef typename __traits_type::difference_type   difference_type;
	typedef typename __traits_type::pointer           pointer;
	typedef typename __traits_type::reference         reference;
};
