
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

const std::vector<std::pair<int, int>> g_directions = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}};

std::mutex mtx;

int func()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << __FUNCTION__ << std::endl;
    return 444;
}

void print_v(int &a)
{
    std::cout << a << std::endl;
}

int main(int argc, char **argv)
{
    {
        const int a = 100;
        const int *b = &a;
        // print_v()
        int *c = const_cast<int *>(b);
        // print_v(b);
        // print_v();
        *c = 101;
        return 0;
    }

    {
        std::future<int> f = std::async(std::launch::async, func);
        f.wait();
        std::cout << f.get() << std::endl;
        f.wait();
        std::cout << f.get() << std::endl;
    }

    {
        mtx.lock();

        mtx.lock();

        std::cout << "it can be locked twice" << std::endl;

        mtx.unlock();
    }
    int data_size;
    std::cin >> data_size;
    for (size_t i = 0; i < data_size; ++i)
    {
        std::unordered_map<int, std::unordered_map<int, int>> min_distance_map;
        std::pair<int, int> current_pos = {0, 0};
        min_distance_map[0][0] = 0;
        int op_size;
        std::cin >> op_size;
        for (size_t j = 0; j < op_size; ++j)
        {
            int dir;
            int moveable;
            //todo 解析操作
            std::cin >> dir >> moveable;
            if (moveable == 1)
            {
                int current_min_dis = min_distance_map[current_pos.first][current_pos.second] + 1;
                current_pos.first += g_directions[dir].first;
                current_pos.second += g_directions[dir].second;
                //todo 检查并更新距离
                for (const auto &i : g_directions)
                {
                    if (min_distance_map.find(current_pos.first + i.first) != min_distance_map.end() &&
                        min_distance_map[current_pos.first + i.first].find(current_pos.second + i.second) != min_distance_map[current_pos.first + i.first].end())
                    {
                        if (min_distance_map[current_pos.first + i.first][current_pos.second + i.second] + 1 < current_min_dis)
                        {
                            current_min_dis = min_distance_map[current_pos.first + i.first][current_pos.second + i.second] + 1;
                        }
                    }
                }
                min_distance_map[current_pos.first][current_pos.second] = current_min_dis;
                if (j == op_size - 1)
                {
                    std::cout << current_min_dis << std::endl;
                }
            }
            else
            {
                ;
            }
        }
    }

    return 0;
}
