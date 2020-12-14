#pragma once

/// <summary>
/// 泛化版本
/// </summary>
/// <typeparam name="I"></typeparam>
template<class I>
struct iterator_traits
{
	typedef typename I::iterator_category iterator_category;
	typedef typename I::value_type        value_type;
	typedef typename I::difference_type   difference_type;
	typedef typename I::pointer           pointer;
	typedef typename I::reference         reference;

};

/// <summary>
/// 偏特化实现（针对指针）
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
struct iterator_traits<T*>
{
	typedef random_access_iterator_tag    iterator_category;
	typedef T                             value_type;
	typedef ptrdiff_t                     difference_type;
	typedef T*                            pointer;
	typedef T&                            reference;
};

/// <summary>
/// 偏特化实现（针对常量指针）
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
struct iterator_traits<const T*>
{
	/*
	    注意为什么不是给const T 
	    value_type主要的作用时声明变量，而声明一个无法被赋值的变量是无意义的
	*/

	typedef random_access_iterator_tag    iterator_category;
	typedef T                             value_type;
	typedef ptrdiff_t                     difference_type;
	typedef T*                            pointer;
	typedef T&                            reference;
};