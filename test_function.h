#include <functional>
#include <iostream>

class test_sta_func_cla
{
private:
    /* data */
public:
    static int test_func(int a);
};

int test_sta_func_cla::test_func(int a)
{
    std::cout << a << std::endl;
}

template <class T>
class test_function
{
private:
    /* data */
public:
    void call(std::function<int(int)> func) { func(3); };
};
