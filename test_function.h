#include <functional>
#include <iostream>
#include <algorithm>

class test_construct
{
private:
    bool m_trigger = false;
    std::vector<int> m_vec;

public:
    test_construct(/* args */) : m_vec(m_trigger ? 100 : 1){}; // Can not init members in construct function's body
    ~test_construct() = default;
};

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
    return a;
}

template <class T>
class test_function
{
private:
    /* data */
public:
    void call(std::function<int(int)> func) { func(3); };
    template <class Iterator>
    void test(Iterator bg, Iterator end)
    {
        std::sort(bg, end);
    }
};