#pragma once

/// <summary>
/// �����汾
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
/// ƫ�ػ�ʵ�֣����ָ�룩
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
/// ƫ�ػ�ʵ�֣���Գ���ָ�룩
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
struct iterator_traits<const T*>
{
	/*
	    ע��Ϊʲô���Ǹ�const T 
	    value_type��Ҫ������ʱ����������������һ���޷�����ֵ�ı������������
	*/

	typedef random_access_iterator_tag    iterator_category;
	typedef T                             value_type;
	typedef ptrdiff_t                     difference_type;
	typedef T*                            pointer;
	typedef T&                            reference;
};