/*
*   Date��2020.12.14
*   Describe: STL.array Source Code
*   About Version: TR1 / GNU4.9
*/

#pragma once
#include <xmemory>
namespace CustomSTL
{
#pragma region G2.9
	namespace G2_9
	{
		template<class T,class Ref,class Ptr,std::size_t BufferSize>
		struct __deque_iterator
		{
			typedef std::random_access_iterator_tag iterator_category;
			typedef T                value_type;
			typedef Ptr              pointer;
			typedef Ref              reference;
			typedef std::size_t      size_type;
			typedef std::ptrdiff_t   difference_type;
			typedef T**              map_pointer;
			typedef __deque_iterator self;

			T* cur;
			T* first;
			T* last;
			map_pointer node;
		};

		//buffersize default value is zero:
		template<class T,class Alloc=std::allocator<T>,std::size_t BufferSize=0>  
		class deque
		{
		public:
			typedef T  value_type;
			typedef T* pointer;
			typedef __deque_iterator<T, T&, T*, BufferSize> iterator;
		protected:
			typedef T**          map_pointer;
			typedef std::size_t  size_type;

		protected:
			iterator    start;
			iterator    finish;
			map_pointer map;
			size_type   map_size;

		protected:
			inline std::size_t __deque_buf_size(size_t n, size_t sz)
			{
				//��������ڴ��С����512�ֽ�ʱ����ÿһ�������һ������Ϊ̫���ˣ�
				return n != 0 ? n : (sz < 512 ? size_t(512 / sz) : size_t(1));
			}

		public:
			iterator begin() { return start; }
			iterator end()   { return finish; }
			size_type size() const { return finish - start; }
			value_type front() { return **start.node; }
			value_type back() { return **finish.node; };

			/// <summary>
			/// ����
			/// </summary>
			/// <param name="position">����λ��</param>
			/// <param name="x">���������</param>
			/// <returns></returns>
			iterator insert(iterator position, const value_type& x)
			{
				if (position.cur == start.cur)//��������λ������ǰ��
				{
					push_front(x);
					return start;
				}
				else if (position.cur == finish.cur)
				{
					push_back(x);
					iterator tmp = finish;
					--tmp; return tmp;
				}
				else
					return insert_aux(position, x);
			}

			
			iterator push_front(const value_type& x){}
			iterator push_back(const value_type& x) {}

		protected:
			iterator insert_aux(iterator pos, const value_type& x)
			{
				__deque_iterator::difference_type index = pos - start;//������֮ǰ��Ԫ�ظ���
				value_type x_copy = x;
				if (index < size() / 2)   //��������֮ǰ��Ԫ�ظ�������
				{
					push_front(front());        //����ǰ�˼������һ��Ԫ��ֵͬ��Ԫ��
					//...
					//copy(front2,)       //Ԫ�ذ�Ǩ
				}
				else                      //��������֮���Ԫ�ظ�������
				{
					push_back(back());
					//...
					//copy(front2,)       //Ԫ�ذ�Ǩ
				}
				*pos = x_copy;            //��������趨��ֵ
				return pos;
			}
		};
	}
#pragma endregion
}
