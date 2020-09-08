
// #pragma pack(push)
// #pragma pack(1)

#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <mutex>
// #include <math.h>
#include <numeric>
#include <limits>
#include <algorithm>
#include <random>
#include <map>
#include <stack>
#include <unordered_set>
#include <set>
// #include <malloc.h>
// #include <semaphore.h>
// #include <pthread.h>
// #include <CivetServer.h>
#include <thread>
#include <future>
// #include <string.h>
#include <list>
#include <map>

// #include "test_function.h"

int PasswordCheck(const std::string &pwd)
{
    //todo 长度 8-120

    size_t sz = pwd.size();
    if (sz > 120 || sz < 8)
    {
        return 1;
    }

    bool has_int = false, has_char = false, has_upper = false, has_lower = false;

    //todo 类型：数字，符号，大写，小写
    for (size_t i = 0; i < sz; ++i)
    {
        char c = pwd[i];
        if (c <= 57 && c >= 48)
        {
            if (!has_int)
            {
                has_int = true;
            }
        }
        else if (c <= 90 && c >= 65)
        {
            if (!has_upper)
            {
                has_upper = true;
            }
        }
        else if (c <= 122 && c >= 97)
        {
            if (!has_lower)
            {
                has_lower = true;
            }
        }
        else
        {
            if (!has_char)
            {
                has_char = true;
            }
        }
    }
    if (has_char && has_int && has_lower && has_upper)
    {
        return 0;
    }
    else
    {
        return 2;
    }
}

int main(int argc, char **argv)
{
    std::vector<std::string> ss;
    std::string s;

    while (std::cin >> s)
    {
        ss.emplace_back(s);
        if (std::cin.peek() == '\n')
        {
            break;
        }
    }

    for (const auto &s : ss)
    {
        std::cout << PasswordCheck(s) << std::endl;
    }

    return 0;
}
