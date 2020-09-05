
#pragma pack(push)
#pragma pack(1)

#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
#include <math.h>
#include <numeric>
#include <limits>
#include <algorithm>
#include <random>
#include <map>
#include <stack>
#include <unordered_set>
#include <set>
#include <malloc.h>
#include <semaphore.h>
#include <pthread.h>
#include <CivetServer.h>
#include <thread>
#include <string.h>

#include "test_function.h"

sem_t sem;

struct span
{
    unsigned int smin : 16; // 占据16/8=2字节
    char smax;              // 占据1字节，但是由于压缩，虽然没报错但是取不到地址，去掉的话真的会有11字节的占用
    unsigned int area : 6;  // 占据（6/8）字节，最终按照对齐为1占据1字节
    span *next;             // 占据8字节（64位机器）
};

void InsertionSort(std::vector<int> &vec)
{
    //todo 有序区，无序区
    //待排序就是i+1
    size_t sz = vec.size();
    for (size_t i = 1; i < vec.size(); i++)
    {
        size_t wait_for_sorted_index = i;
        for (size_t j = wait_for_sorted_index - 1; j >= 0; j--)
        {
            if (vec[j] < vec[wait_for_sorted_index])
            {
                int swapped_value = vec[wait_for_sorted_index];
                //todo push the nums on j's right hand
                for (size_t k = wait_for_sorted_index; k > j + 1; k--)
                {
                    vec[k] = vec[k - 1];
                }
                vec[j + 1] = swapped_value;
                //todo insert it at j
                break;
            }
        }
    }
}

static int handler(struct mg_connection *conn, void *ignored)
{
    std::string msg = "Hello, you guys";
    size_t len = msg.size();

    mg_printf(conn, "HTTP/1.1 200 OK\r\n"
                    "Content-Length: %lu\r\n"
                    "Content-Type: text/plain\r\n"
                    "Connection: close\r\n\r\n",
              len);

    mg_write(conn, msg.c_str(), msg.size());

    return 200;
}

void static_thread_test()
{
    static bool called = false;

    if (called)
    {
        std::cout << "it has been called" << std::endl;
        return;
    }
    else
    {
        std::cout << "calling" << std::endl;
        called = true;
    }

    return;
}

const int generation_times = 10;
thread_local std::vector<int> num_array(generation_times);
void fill_vec(int start)
{
    std::iota(num_array.begin(), num_array.end(), start);
    for (auto &i : num_array)
    {
        std::cout << i << '\t';
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    {
        fill_vec(1);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::thread th(fill_vec, 1000);
        th.join();
        return 0;
    }
    {
        static_thread_test();
        std::thread th(static_thread_test);
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::thread th2(static_thread_test);

        th.join();
        th2.join();
        return 0;
    }

    {
        struct mg_context *ctx;

        mg_init_library(0);

        ctx = mg_start(NULL, 0, NULL); //我估计从这一句开始服务器就开始执行了。

        mg_set_request_handler(ctx, "/lolipop", handler, (void *)"Hello. I am your lolipop!");

        std::this_thread::sleep_for(std::chrono::milliseconds(30000)); //sleep多久服务器就开放多久，应该有manager线程和worker线程在做事

        mg_stop(ctx);

        mg_exit_library();
    }

    {
        std::vector<int> vec = {11, 123, 14, 5, 15, 6, 7, 8, 1123, 689, 9, 1};
        InsertionSort(vec);
    }

    {
        A *a = new C();
        auto *b = static_cast<B *>(a);
        b->Oh();
        delete a;
    }

    std::cout << "size\t" << sizeof(span) << std::endl;
    span s;
    std::cout << "&\t" << &s << std::endl;
    // std::cout << "&smin\t" << &(a.smin) << std::endl;
    std::cout << "&smax\t" << &(s.smax) << std::endl;
    // std::cout << "&area\t" << &(a.area) << std::endl;
    std::cout << "&next\t" << &(s.next) << std::endl;

    int *a = new int[10];
    auto a_size = malloc_usable_size(a);

    int *b = new int(6226);
    auto b_size = malloc_usable_size(b);

    auto int_size = sizeof(int);

    return 0;
}

#pragma pack(pop)