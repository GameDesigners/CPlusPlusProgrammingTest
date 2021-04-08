#include <iostream>
#include <vector>

template<typename T>
void Print(const T& arg)
{
    std::cout << arg << std::endl;
}

template<typename T,typename... Types>
void Print(const T& firstArg, const Types&... args)
{
    std::cout << firstArg << std::endl;
    Print(args...);
}

//新的函数声明方式
template<typename T1,typename T2>
auto Add(T1 x, T2 y)->decltype(x + y)
{
    return x + y;
}

//带领域的枚举类
enum class Salutation : char{mr,ms,co,none};

//显示C++11新的类型
void ShowNewType()
{
    std::cout << std::endl;
    std::cout << "C++ 11 新增的基础类型：" << std::endl;
    std::cout << "chart16_t             size:" << sizeof(char16_t) << std::endl;
    std::cout << "chart32_t             size:" << sizeof(char32_t) << std::endl;
    std::cout << "long long             size:" << sizeof(long long) << std::endl;
    std::cout << "unsigned long long    size:" << sizeof(unsigned long long) << std::endl;
}

int main()
{
    //Range-Base For的用法
    /*std::vector<int> vec = { 1,3,5,7,9 };
    for (auto& elem : vec)
        elem *= 3;

    for (int elem : vec)
        std::cout << elem << " ";*/

    //template新特性
    //Print(1, "hello word", 3.44, 'A');

    //Lambda
    [] {std::cout << "hello world"<<std::endl; }();

    auto function = [] {std::cout << "hello world1" << std::endl; };
    function();

    auto f_have_params = [](const std::string& printStr) {std::cout << printStr << std::endl; };
    f_have_params("Call F_Have_Params...");

    auto f_have_params_and_return = [](const std::string& introStr, const int& num) {
        std::cout << introStr << "→"<<"  ";
        return num == 1;
    };
    std::cout << f_have_params_and_return("数字是否等于1", 2) << std::endl;

    //表明Lambda表达式引用外面的变量是值传递还是引用传递
    int lambda_x = 0;
    int lambda_y = 1;
    auto f_use_outside_values = [lambda_x, &lambda_y] {
        lambda_y = 10;
    };
    f_use_outside_values();
    std::cout << "lambda_y通过引用传递修改值，当前的值为：" << lambda_y;

    //引用函数新的定义方式
    auto result=Add(1, 1.0);
    std::cout << "Result:" << result << std::endl;

    Salutation::mr;

    //新的类型
    ShowNewType();

    
}