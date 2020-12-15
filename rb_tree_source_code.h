#pragma once
#include<xmemory>
namespace CustomSTL
{
	template<class Value>
	struct __rb_tree_node
	{

	};

	template<class Key,class Value,class KeyOfValue,class Compare,class Alloc = std::allocator<Value>>
	class rb_tree
	{
	protected:
		typedef __rb_tree_node<Value> rb_tree_node;
		typedef std::size_t size_type;

	public:
		typedef rb_tree_node* link_type;

	protected:
		size_type node_count;   //rb_tree的大小（节点数量）
		link_type header;       //rb_tree
		Compare   key_compare;  //key大小的比较准则
	};
}