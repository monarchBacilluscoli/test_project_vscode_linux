
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

using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };

void nextPermutation(vector<int> &nums)
{
    if (nums.size() <= 1)
    {
        return;
    }
    int j = nums.size() - 2, k = nums.size() - 1; // 和与那个数最近的大于它的数交换
    while (nums[j] > nums[k] && j >= 0)
    {
        --j;
        --k;
    }

    if (j == -1)
    {
        int smallest_index = 0;
        int temp = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] < nums[smallest_index])
            {
                smallest_index = i;
            }
        }
        temp = nums[smallest_index];
        nums[smallest_index] = nums[j];
        nums[j] = nums[smallest_index];
    }
    else
    {
        int swap_index = j + 1;
        int smallest = nums[swap_index] - nums[j];
        for (int i = j + 1; i < nums.size(); ++i)
        {
            int diff = nums[i] - nums[j];
            if (diff > 0 && diff < smallest)
            {
                swap_index = i;
            }
        }
        std::iter_swap(nums.begin() + j, nums.begin() + swap_index);
    }
    //todo 从j之后，都要排序
    for (int i = j; i < nums.size(); ++i)
    {
        std::iter_swap(nums.begin() + i + 1, min_element(nums.begin() + i + 1, nums.end()));
    }
}

int main()
{
    // ListNode *p = new ListNode(1);
    // p->next = new ListNode(2);
    // p->next->next = new ListNode(3);
    // p->next->next->next = new ListNode(4);
    std::vector<int> vec = {1, 2};
    nextPermutation(vec);

    // p = swapPairs(p);
    // while (p)
    // {
    //     std::cout << p->val << "\t";
    //     p = p->next;
    // }
    // std::cout << std::endl;

    return 0;
}
