/*
*   Date：2020.12.14
*   Describe: STL.array Source Code
*   About Version: TR1 / GNU4.9
*/

#pragma once

#include<cstddef>  //std::size_t
#include<xstddef>  //std::addressof
#include<stdexcept>//std::_Throw_range_error

namespace CustomSTL
{
#pragma region TR1 Version
	namespace TR1
	{
		template<typename _Tp, std::size_t _Nm>
		struct array
		{
			typedef _Tp         value_type;
			typedef _Tp* pointer;
			typedef value_type* iterator;      //迭代器为一个指针，算法获取时需要萃取机操作

			//支持0数据的arrays
			value_type _M_instance[_Nm ? _Nm : 1];

			iterator begin()
			{
				return iterator(&_M_instance[0]);
			}

			/// <summary>
			/// 注意：获取的end地址对于array是越界的，
			/// 它不属于容器的一部分，可以把它看作是结束的标志
			/// </summary>
			/// <returns></returns>
			iterator end()
			{
				return iterator(&_M_instance[_Nm]);
			}
		};
	}
#pragma endregion


#pragma region G4.9 Version
	namespace G4_9
	{
		//array_traits
		template<typename _Tp,std::size_t _Nm>
		struct __array_traits
		{
			typedef _Tp _Type[_Nm];

			static constexpr _Tp& _S_ref(const _Type& __t, std::size_t __n) noexcept
			{
				return const_cast<_Tp&>(__t[__n]);
			}
		};


		template<typename _Tp, std::size_t _Nm>
		struct array
		{
			typedef _Tp             value_type;
			typedef value_type*     pointer;
			typedef value_type&     reference;
			typedef value_type*     iterator;
			typedef std::size_t     size_type;

			typedef __array_traits<_Tp,_Nm> _AT_Type;
			typename _AT_Type::_Type _M_elems;

			reference operator[](size_type __n) noexcept 
			{
				return _AT_Type::_S_ref(_M_elems, __n);    //无边检
			}

			reference at(size_type __n)
			{
				if (__n >= _Nm) std::_Throw_range_error;  //有边检
				return _AT_Type::_S_ref(_M_elems, __n);
			}

			iterator begin() noexcept { return iterator(data()); }
			iterator end()   noexcept { return iterator(data() + _Nm); }
			constexpr size_type size() const noexcept { return _Nm; }
			pointer data() noexcept { return std::addressof(_AT_Type::_S_ref(_M_elems, 0)); }
		};
	}
#pragma endregion
}