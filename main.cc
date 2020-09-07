
// #pragma pack(push)
// #pragma pack(1)

#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
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
// #include <thread>
// #include <string.h>
#include <list>
#include <map>

// #include "test_function.h"

const std::vector<std::pair<int, int>> g_directions = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}};

int main(int argc, char **argv)
{
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
