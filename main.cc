#include <arpa/inet.h>
#include <sys/fcntl.h>

#include <string>
#include <iostream>
#include <vector>
#include <future>
#include <stdio.h>
#include <math.h>
#include <future>
#include <unistd.h>
#include <string.h>

#include "test_function.h"


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

struct TwoInts
{
    int a, b;
};

//todo test1: multithread exception - can main thread catch the exception from child thread
//todo test2: after catch - which statement in which layer will be executed
int main(int argc, char **argv)
{
    {
        void *start = sbrk(0);
        std::cout << sizeof(unsigned long int) << std::endl;
        std::cout << start << std::endl;
        unsigned long int *a = (unsigned long *)sbrk(0);
        std::cout << sbrk(8) << std::endl;
        void *end = sbrk(0);
        memset(end - 1, 0xFF, 1);
        std::cout << *a << std::endl;
        return 0;
    }
    {
        A a;
        int test_number = 12241251;
        // bool odd = false;
        std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < 1000000; ++i)
        {
            if (test_number % 2 == 1)
            {
                ;
            }
        }
        std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
        std::cout << "%: " << (std::chrono::duration_cast<std::chrono::microseconds>(end - start)).count() << std::endl;
        start = std::chrono::high_resolution_clock::now();
        for (size_t i = 0; i < 1000000; ++i)
        {
            if (test_number & 1 == 1)
            {
                ;
            }
        }
        end = std::chrono::high_resolution_clock::now();
        std::cout << "&: " << (std::chrono::duration_cast<std::chrono::microseconds>(end - start)).count() << std::endl;
        return 0;
    }
    {
        // to see if file descriptor is the sam as socket file descriptor.
        int a;
        if ((a = open("/home/liuyongfeng/microsoft.gpg", O_RDONLY)) < 0)
        {
            perror("?");
        }
        auto b = socket(AF_INET, SOCK_STREAM, 0);
        return 0;
    }
    {
        int a = 1;
        std::future<void> f = std::async([&]() -> void { a = 11; });
        std::cout << a << std::endl;
        return 0;
    }
    {
        auto a = ceil(4 / 2);
        return 0;
    }
    {
        while (1)
        {
            uint16_t i;
            std::cin >> i;
            std::cout << ntohs(i) << std::endl;
        }
        return 0;
    }

    {
        int a = 2;
        float b = 15;
        std::cout << b / a << std::endl;
        return 0;
    }
    {
        std::cout << -10 / int(size_t(2)) << std::endl;
        return 0;
    }
    {
        int a = 0;
        std::thread t1([&a]() -> void {
            a = 1;
        });
        t1.join();
        std::thread
        t2([&a]() -> void {
            a = 2;
        });

        t2.join();
        return 0;
    }

    if (0)
    {
        char s[] = "this is a static string";
        std::cout << s << std::endl;
        return 0;
    }

    {
        std::cout << "hhh" << std::endl;
        char *log = nullptr;
        std::cout << log << std::endl;
        int sz = asprintf(&log, "Hello, %s, my old friends", "HHH");
        auto a = std::string(log);
        std::cout << a << std::endl
                  << std::flush;
        printf("%s", log);
        std::cout
            << *log << std::endl;
        free(log);
        return 0;
    }

    {
        char *p = new char[8];
        p[0] = 'a';
        p[4] = 'b';
        struct TwoInts *p2 = (TwoInts *)(p);
        std::cout << p2->a << std::endl;
        std::cout << p2->b << std::endl;
        return 0;
    }

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
