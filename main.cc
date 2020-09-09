
#include <string>
#include <iostream>
#include <vector>
#include <future>

void Thrower()
{
    try
    {
        std::cout << "before calling@" + std::string(__FUNCTION__) << std::endl;
        throw(std::runtime_error("an error!"));
        std::cout << "after calling@" + std::string(__FUNCTION__) << std::endl;
    }
    catch (const std::bad_cast &e)
    {
        std::cerr << e.what() << '\n';
    }
    return;
}

void Caller()
{
    try
    {
        std::cout << "before calling@" + std::string(__FUNCTION__) << std::endl;
        Thrower();
        std::cout << "after calling@" + std::string(__FUNCTION__) << std::endl;
    }
    catch (const std::bad_typeid &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "after catch@" + std::string(__FUNCTION__) << std::endl;
    return;
}

//todo test1: multithread exception - can main thread catch the exception from child thread
//todo test2: after catch - which statement in which layer will be executed
int main(int argc, char **argv)
{
    try
    {
        std::future<void> ft = std::async(std::launch::async, Caller);
    }
    catch (const std::exception &e) // 捕获任何异常
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "after calling@" + std::string(__FUNCTION__) << std::endl;
    /* the logic is the same: 程序将会从catch到的那个catch之后继续运行，也就是说整个thread直接消失。输出:
    before calling@Caller
    before calling@Thrower
    after calling@main
    */

    return 0;
}
