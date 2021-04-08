#include <iostream>
#include <utility>
#include <tuple>
#include "STLCommonTool.h"
using namespace std;

class Foo
{
public:
    Foo(tuple<int, float>) 
    {
        cout << "Foo::Foo(tuple)" << endl;
    }

    template<typename... Args>
    Foo(Args... args)
    {
        cout << "Foo::Foo(args...)" << endl;
    }
};

int main()
{
    //pair的使用
    /*
    pair<string, int> pairValue("ZhuSenlin", 100);
    cout << "pairValue first : " << pairValue.first << endl;
    cout << "pairValue second: " << pairValue.second << endl;

    

    pair<string,int> tempPair=make_pair("XiaoMi CC9Pro", 1999);
    swap(pairValue, tempPair);
    cout << "After Swap:" << pairValue << endl;
    pairValue.swap(tempPair);
    cout << "Swap again:" << pairValue << endl;

    //tuple-like接口
    cout << get<0>(pairValue) << endl;
    cout << get<1>(pairValue) << endl;

    cout << "元素个数：" << tuple_size<pair<string, int>>::value << endl;

    */

    //测试第三种初始化的解释
    tuple<int, float> t(1, 2.22);
    pair<int, Foo> p1(42, t);    //调用了Foo(tuple<int, float>) 将t作为参数初始化生成一个Foo实例

    pair<int, Foo> p2(piecewise_construct, make_tuple(42), t);

    pair<char, char> p = make_pair('x', 'y');
    char b,c;
    auto temp=tie(b, c) = p;
    cout << "c is" << c << endl;
    get<1>(temp) = 'A';
    cout << "c is" << c << endl;    
}
