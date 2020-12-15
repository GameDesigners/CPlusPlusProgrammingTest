/*
*   Date：2020.12.14
*   Describe: STL.array Source Code
*   About Version: TR1
*/

#pragma once
#include<xmemory>

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
			//如果分配内存大小大于512字节时，就每一个缓冲放一个（因为太大了）
			inline std::size_t __deque_buf_size(size_t n, size_t sz){	return n != 0 ? n : (sz < 512 ? size_t(512 / sz) : size_t(1));	}

			reference operator*() const { return *cur; }
			pointer   operator->() const { return &(operator*()); }  //?为何返回cur
			difference_type operator-(const self& x) { return difference_type(__deque_buf_size()) * (node - x.node - 1) + (cur - first) + (x.last - x.cur); }
			self& operator++()
			{
				++cur;
				if (cur == last)
				{
					set_node(node + 1);
					cur = first;
				}
				return *this;
			}

			self operator++(int)
			{
				self tmp = *this;
				++ *this;
				return tmp;
			}

			self& operator--()
			{
				if (cur == first)
				{
					set_node(node - 1);
					cur = last;
				}
				--cur;
				return *this;
			}

			self operator--(int)
			{
				self tmp=*this;
				--* this;
				return tmp;
			}

			self& operator+=(difference_type n)
			{
				difference_type offset = n + (cur - first);
				if (offset >= 0 && offset < difference_type(__deque_buf_size()))
					cur += n;  //两者处在同一个连续空间中
				else
				{
					difference_type node_offset = offset > 0 ? offset / difference_type(__deque_buf_size()) : -difference_type((-offset - 1) / __deque_buf_size()) - 1;
					//切换到下一个缓冲区
					set_node(node + node_offset);
					//切换至正确元素
					cur = first + (offset - node_offset * difference_type(__deque_buf_size()));
				}
				return *this;
			}
			
			self operator+(difference_type n) const
			{
				self tmp = *this;
				return tmp += n;
			}

			self& operator-=(difference_type n)
			{
				return *this += -n;
			}

			self operator-(difference_type n) const
			{
				self tmp = *this;
				return tmp -= n;
			}

			reference operator[](difference_type n) const
			{
				return *(*this + n);
			}

			void set_node(map_pointer new_node)
			{
				//更新迭代器的数据
				node = new_node;
				first = *new_node;
				last = new_node + difference_type(__deque_buf_size());
			}
		};

		//buffersize default value is zero:
		template<class T,class Alloc=std::allocator<T>,std::size_t BufferSize=0>  
		class deque
		{
		public:
			typedef T  value_type;
			typedef T* pointer;
			typedef T& reference;
			typedef __deque_iterator<T, T&, T*, BufferSize> iterator;
		protected:
			typedef T**          map_pointer;
			typedef std::size_t  size_type;

		protected:
			iterator    start;
			iterator    finish;
			map_pointer map;
			size_type   map_size;
			

		public:
			iterator begin() { return start; }
			iterator end()   { return finish; }
			size_type size() const { return finish - start; }  //！减符号已经重载了
			reference front() { return *start; }
			reference back()  
			{ 
				iterator tmp = finish;
				--tmp;
				return *tmp;
			};
			bool empty() { return start == finish; }
			/// <summary>
			/// 插入
			/// </summary>
			/// <param name="position">插入位置</param>
			/// <param name="x">插入的数据</param>
			/// <returns></returns>
			iterator insert(iterator position, const value_type& x)
			{
				if (position.cur == start.cur)//如果插入的位置是最前端
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
				__deque_iterator::difference_type index = pos - start;//安插在之前的元素个数
				value_type x_copy = x;
				if (index < size() / 2)   //如果安插点之前的元素个数较少
				{
					push_front(front());        //在最前端加入与第一个元素同值的元素
					//...
					//copy(front2,)       //元素搬迁
				}
				else                      //如果安插点之后的元素个数较少
				{
					push_back(back());
					//...
					//copy(front2,)       //元素搬迁
				}
				*pos = x_copy;            //安插点上设定新值
				return pos;
			}
		};
	}
#pragma endregion
}
