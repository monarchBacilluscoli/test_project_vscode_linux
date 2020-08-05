#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <limits>
#include <math.h>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <numeric>
#include <unordered_set>
#include <string>

using namespace std;

std::vector<int> counts;
int numTrees(int n)
{
    counts.resize(n + 1); // 确定记录表的长度
    counts[0] = 1;
    counts[1] = 1;

    for (int i = 2; i < n + 1; ++i) // 从小到大递推所有结果
    {
        for (int j = 0; j < i; j++) // 选择第j个数作为根节点（分割）//! 注意分割的点可以到i点
        {
            counts[i] += counts[j] * counts[i - j - 1]; // 左手是j个节点的二叉树，右手是i-j个节点的二叉树 //! 注意左边和右边的和为i-1
        }
    }
    return counts[n];
}

int main(int argc, char *argv[])
{
    std::cout << numTrees(3) << std::endl;
    return 0;
}
