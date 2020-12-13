#pragma once
#include<xmemory>  //allocator & deallocator
void UseAllocator()
{
	int* p = std::allocator<int>().allocate(512, (int*)0);
	std::allocator<int>().deallocate(p, 512);

	
}

#pragma region G2.9°æ±¾
template<class T>
struct __list_node
{
	typedef void* void_pointer;
	void_pointer prev;
	void_pointer next;
	T data;
};

template<class T,class Ref,class Ptr>
struct __list_iterator
{
	typedef __list_iterator<T, Ref, Ptr> self;
	typedef bidirectional_iterator_tag iterator_category;
	typedef T   value_type;
	typedef Ptr pointer;
	typedef Ref reference;
	typedef __list_node<T>* link_type;
	typedef ptrdiff_t difference_type;

	link_type node;

	reference operator*() const { return (*node).data; }
	pointer operator->() const { return &(operator*()); }

	self& operator++() {
		node = (link_type)((*node).next);
		return *this;
	}

	self& operator++(int) {
		self tmp = *this;
		++* this;
		return tmp;
	}
};

template<class T,class Alloc=std::allocator<T>>
class list
{
protected:
	typedef __list_node<T> list_node;
public:
	typedef list_node* link_type;
	typedef __list_iterator<T, T&, T*> iterator;
protected:
	link_type node;
};
#pragma endregion

#pragma region G4.9
struct _List_node_base
{
	_List_node_base* _M_next;
	_List_node_base* _M_prev;
};

template<typename _Tp>
struct _List_node : public _List_node_base
{
	_Tp _M_data;
};

template<typename _Tp,
	     typename _Alloc=std::allocator<_Tp>>
class list :protected _List_node_base<_Tp>
{
public:
	typedef _List_iterator<_Tp> iterator;
};
#pragma endregion