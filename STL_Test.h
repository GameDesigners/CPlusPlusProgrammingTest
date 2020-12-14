#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<utility>  //pair<>

#include<array>
#include<vector>
#include<list>
#include<forward_list>
#include<deque>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<map>


#include<algorithm>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::exception;
using std::find;
using std::sort;
using std::pair;
//Ԫ��
using std::array;
using std::vector;
using std::list;
using std::forward_list;
using std::deque;
/*set*/
using std::set;
using std::multiset;
using std::unordered_set;
using std::unordered_multiset;
/*map*/
using std::map;
using std::multimap;
using std::unordered_map;
using std::unordered_multimap;

#define ASIZE 500000
#pragma region �������� 
///<Summary>
/// ���һ��longֵ 
///</Summary> 
long get_a_target_long()
{
	long target = 0;
	cout << "target(0~" << RAND_MAX << "):";
	cin >> target;
	return target;
}

///<Summary>
/// ���һ���ַ���
///</Summary> 
string get_a_target_string()
{
	long target = 0;
	char buf[10];
	cout << "target(0~" << RAND_MAX << "):";
	cin >> target;
	snprintf(buf, 10, "%d", target);    //����format�ĸ�ʽ��ʽ��Ϊ�ַ�����Ȼ���ٽ��俽����str��
	return string(buf);
}

///<Summary>
/// long�ıȽ� 
///</Summary> 
int compareLongs(const void* a, const void* b)
{
	return(*(long*)a - *(long*)b);
}

///<Summary>
/// string�ıȽ� 
///</Summary> 
int compareStrings(const void* a, const void* b)
{
	if (*(string*)a > * (string*)b)
		return 1;
	else if (*(string*)a < *(string*)b)
		return -1;
	else
		return 0;
}
#pragma endregion

#pragma region ���������ķ���
/// <summary>
/// ����array
/// </summary>
void test_array()
{
	cout << "\ntest_array()...............................\n ";
	static array<long, ASIZE> c;

	clock_t timeStart = clock();
	for (long i = 0; i < ASIZE; ++i)
		c[i] = rand();

	//Debug Message........................................................
	cout << "milli-seconds:" << (clock() - timeStart) << endl;
	cout << "array.size()=" << c.size() << endl;                 //Ԫ�ظ��� 
	cout << "array.front()=" << c.front() << endl;               //��Ԫ�� 
	cout << "array.back()=" << c.back() << endl;                 //βԪ�� 
	cout << "array.data()=" << c.data() << endl;                 //��Ԫ�ص�ַ 
	//EndDebug.............................................................

	long target = get_a_target_long();
	timeStart = clock();
	qsort(c.data(), ASIZE, sizeof(long), compareLongs);
	long* pItem = (long*)bsearch(&target, (c.data()), ASIZE, sizeof(long), compareLongs);  //���ֲ���
	cout << "qsort()+bsearch(),milli-seconds:" << (clock() - timeStart) << endl;
	if (pItem != NULL)
		cout << "found," << *pItem << endl;
	else
		cout << "not found" << endl;
}

/// <summary>
/// ����vector
/// </summary>
/// <param name="value"></param>
void test_vector(const long& value)
{
	cout << "\ntest_vector()...............................\n ";
	static vector<string> c;
	char buf[10];

	clock_t timeStart = clock();
	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.push_back(string(buf));
		}
		catch (exception e)
		{
			cout << "i=" << i << " " << e.what() << endl;
			abort();
		}
	}
	//Debug Message........................................................
	cout << "milli-seconds:" << (clock() - timeStart) << endl;
	cout << "vector.size()=" << c.size() << endl;                 //Ԫ�ظ��� 
	cout << "vector.front()=" << c.front() << endl;               //��Ԫ�� 
	cout << "vector.back()=" << c.back() << endl;                 //βԪ�� 
	cout << "vector.data()=" << c.data() << endl;                 //��Ԫ�ص�ַ 
	cout << "vector.capacity()=" << c.capacity() << endl;         //��Ԫ�ص�ַ 
	//EndDebug.............................................................

	string target = get_a_target_string();
	timeStart = clock();
	auto pItem = ::find(c.begin(), c.end(), target);
	cout << "::find(),milli-seconds:" << (clock() - timeStart) << endl;
	if (pItem != c.end())
		cout << "found," << *pItem << endl;
	else
		cout << "not found" << endl;

	//���ֲ���
	timeStart = clock();
	sort(c.begin(), c.end());  //��ռ��ͷ
	string* pItems = (string*)bsearch(&target, (c.data()), c.size(), sizeof(string), compareStrings);
	cout << "sort()+bsearch(),milli-seconds:" << (clock() - timeStart) << endl;
}

/// <summary>
/// ����list
/// </summary>
/// <param name="value"></param>
void test_list(const long& value)
{
	cout << "\n test_list()...............................\n ";
	static list<string> c;
	char buf[10];

	clock_t timeStart = clock();
	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.push_back(string(buf));
		}
		catch (exception& e)
		{
			cout << "i=" << i << "" << e.what() << endl;
			abort();
		}
	}

	//Debug Message........................................................
	cout << "milli-seconds:" << (clock() - timeStart) << endl;
	cout << "list.size()=" << c.size() << endl;                 //Ԫ�ظ��� 
	cout << "list.max_size()=" << c.max_size() << endl;         //������� 
	cout << "list.front()=" << c.front() << endl;               //��Ԫ�� 
	cout << "list.back()=" << c.back() << endl;                 //βԪ��
	//EndDebug.............................................................

	string target = get_a_target_string();
	timeStart = clock();
	auto pItem = find(c.begin(), c.end(), target);
	cout << "::find(),milli-seconds:" << (clock() - timeStart) << endl;
	if (pItem != c.end())
		cout << "found," << *pItem << endl;
	else
		cout << "not found" << endl;

	//���ֲ���
	timeStart = clock();
	c.sort();
	cout << "c.sort() milli-seconds:" << (clock() - timeStart) << endl;
}

/// <summary>
/// ����forward_ list
/// </summary>
/// <param name="value"></param>
void test_forwardlist(const long& value)
{
	cout << "\n test_forwardlist()...............................\n ";
	static forward_list<string> c;
	char buf[10];

	clock_t timeStart = clock();
	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.push_front(string(buf));        //ͷ�巨�����ṩβ��-push_back
		}
		catch (exception& e)
		{
			cout << "i=" << i << "" << e.what() << endl;
			abort();
		}
	}

	//Debug Message........................................................
	cout << "milli-seconds:" << (clock() - timeStart) << endl;
	cout << "forwardlist.max_size()=" << c.max_size() << endl;         //������� 
	cout << "forwardlist.front()=" << c.front() << endl;               //��Ԫ�� 
	//EndDebug.............................................................

	string target = get_a_target_string();
	timeStart = clock();
	auto pItem = find(c.begin(), c.end(), target);
	cout << "::find(),milli-seconds:" << (clock() - timeStart) << endl;
	if (pItem != c.end())
		cout << "found," << *pItem << endl;
	else
		cout << "not found" << endl;

	//���ֲ���
	timeStart = clock();
	c.sort();
	cout << "c.sort() milli-seconds:" << (clock() - timeStart) << endl;
}

/// <summary>
/// ����deque
/// </summary>
/// <param name="value"></param>
void test_deque(const long& value)
{
	cout << "\n test_deque()...............................\n ";
	static deque<string> c;
	char buf[10];

	clock_t timeStart = clock();
	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.push_front(string(buf));        //ͷ�巨�����ṩβ��-push_back
		}
		catch (exception& e)
		{
			cout << "i=" << i << "" << e.what() << endl;
			abort();
		}
	}

	//Debug Message........................................................
	cout << "milli-seconds:" << (clock() - timeStart) << endl;
	cout << "deque.size()=" << c.size() << endl;                 //Ԫ������
	cout << "deque.front()=" << c.front() << endl;               //��Ԫ��
	cout << "deque.back()=" << c.back() << endl;                 //βԪ��
	cout << "deque.max_size()=" << c.max_size() << endl;         //������� 
	//EndDebug.............................................................

	string target = get_a_target_string();
	timeStart = clock();
	auto pItem = find(c.begin(), c.end(), target);
	cout << "::find(),milli-seconds:" << (clock() - timeStart) << endl;
	if (pItem != c.end())
		cout << "found," << *pItem << endl;
	else
		cout << "not found" << endl;

	//���ֲ���
	timeStart = clock();
	sort(c.begin(), c.end());
	cout << "c.sort() milli-seconds:" << (clock() - timeStart) << endl;
}

/// <summary>
/// ����multiset
/// </summary>
/// <param name="value"></param>
void test_multiset(const long& value)
{
	cout << "\n test_multiset()...............................\n ";
	static multiset<string> c;
	char buf[10];

	clock_t timeStart = clock();
	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			c.insert(string(buf));
		}
		catch (exception& e)
		{
			cout << "i=" << i << "" << e.what() << endl;
			abort();
		}
	}

	//Debug Message........................................................
	cout << "milli-seconds:" << (clock() - timeStart) << endl;
	cout << "deque.size()=" << c.size() << endl;                 //Ԫ������
	cout << "deque.max_size()=" << c.max_size() << endl;         //������� 
	//EndDebug.............................................................

	string target = get_a_target_string();
	timeStart = clock();
	auto pItem = find(c.begin(), c.end(), target);
	cout << "::find(),milli-seconds:" << (clock() - timeStart) << endl;
	if (pItem != c.end())
		cout << "found," << *pItem << endl;
	else
		cout << "not found" << endl;

	//���ֲ���
	timeStart = clock();
	pItem = c.find(target);
	cout << "c.find(),milli-seconds:" << (clock() - timeStart) << endl;
	if (pItem != c.end())
		cout << "found," << *pItem << endl;
	else
		cout << "not found" << endl;
}

/// <summary>
/// ����multiset
/// </summary>
/// <param name="value"></param>
void test_multimap(const long& value)
{
	cout << "\n test_multimap()...............................\n ";
	static multimap<long, string> c;
	char buf[10];

	clock_t timeStart = clock();
	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			//multimap��������[]��Ϊinsertion,��Ϊmultimap��key������ͬ����������Ψһ��
			c.insert(pair<long, string>(i, string(buf)));
		}
		catch (exception& e)
		{
			cout << "i=" << i << "" << e.what() << endl;
			abort();
		}
	}

	//Debug Message........................................................
	cout << "milli-seconds:" << (clock() - timeStart) << endl;
	cout << "multimap.size()=" << c.size() << endl;                 //Ԫ������
	cout << "multimap.max_size()=" << c.max_size() << endl;         //������� 
	//EndDebug.............................................................

	long target = get_a_target_long();
	timeStart = clock();

	auto pItem = c.find(target);
	cout << "c.find(),milli-seconds:" << (clock() - timeStart) << endl;
	if (pItem != c.end())
		cout << "found,value=" << (*pItem).second << endl;
	else
		cout << "not found" << endl;
}

/// <summary>
/// ����multiset
/// </summary>
/// <param name="value"></param>
void test_unordered_multiset(const long& value)
{
	cout << "\n test_multimap()...............................\n ";
	static unordered_multiset<string> c;
	char buf[10];

	clock_t timeStart = clock();
	for (long i = 0; i < value; ++i)
	{
		try
		{
			snprintf(buf, 10, "%d", rand());
			//map��������[]��Ϊinsertion
			c.insert(string(buf));
		}
		catch (exception& e)
		{
			cout << "i=" << i << "" << e.what() << endl;
			abort();
		}
	}

	//Debug Message........................................................
	cout << "milli-seconds:" << (clock() - timeStart) << endl;
	cout << "unordered_multiset.size()=" << c.size() << endl;                 //Ԫ������
	cout << "unordered_multiset.max_size()=" << c.max_size() << endl;         //������� 
	cout << "unordered_multiset.bucket_count()=" << c.bucket_count() << endl; //"������"
	cout << "unordered_multiset.load_factor()=" << c.load_factor() << endl;   //��ϣ��ĸ�������
	cout << "unordered_multiset.max_load_factor()=" << c.max_load_factor() << endl;  //��ϣ������������
	cout << "unordered_multiset.max_bucket_count()=" << c.max_bucket_count() << endl;
	//EndDebug.............................................................

	for (unsigned int i = 0; i < 20; ++i)
	{
		cout << "bucket #" << i << " has " << c.bucket_size(i) << " elements.\n ";
	}

	string target = get_a_target_string();
	timeStart = clock();
	auto pItem = find(c.begin(), c.end(), target);
	cout << "::find(),milli-seconds:" << (clock() - timeStart) << endl;
	if (pItem != c.end())
		cout << "found," << *pItem << endl;
	else
		cout << "not found" << endl;

	//���ֲ���
	timeStart = clock();
	pItem = c.find(target);
	cout << "c.find(),milli-seconds:" << (clock() - timeStart) << endl;
	if (pItem != c.end())
		cout << "found," << *pItem << endl;
	else
		cout << "not found" << endl;
}
#pragma endregion