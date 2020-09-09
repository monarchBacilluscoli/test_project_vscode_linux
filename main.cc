
#include <string>
#include <iostream>
#include <vector>
#include <future>

void Thrower()
{
    try
    {
        std::cout << "before calling@" + std::string(__FUNCTION__) << std::endl;
        throw(std::range_error("an error!"));
        std::cout << "after calling@" + std::string(__FUNCTION__) << std::endl;
    }
    catch (const std::bad_cast &e)
    {
        std::cerr << e.what() << '\n';
    }
}

void Caller()
{
    try
    {
        std::cout << "before calling@" + std::string(__FUNCTION__) << std::endl;
        Thrower();
        std::cout << "after calling@" + std::string(__FUNCTION__) << std::endl;
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "after catch@" + std::string(__FUNCTION__) << std::endl;
}

//todo test1: multithread exception - can main thread catch the exception from child thread
//todo test2: after catch - which statement in which layer will be executed
int main(int argc, char **argv)
{
    Caller(); /* The output:
    before calling@Caller
    before calling@Thrower
    an error!
    after catch@Caller
    */
              //也就是说控制流会从真正catch了这个异常的那个catch之后继续运行，而不是从throw的位置继续运行，也不是从catch的那一层的throw出来的位置继续运行。
    return 0;
}
