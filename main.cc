
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

#include "test_function.h"

using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeKLists(std::vector<ListNode *> &lists)
{
    std::multimap<int, ListNode *> sorted_map;
    ListNode *result = new ListNode(0), *p = result;
    for (int i = 0; i < lists.size(); ++i)
    {
        if (lists[i])
        {
            sorted_map.insert({lists[i]->val, lists[i]});
        }
    }

    while (!sorted_map.empty())
    {
        //todo 出一个
        p->next = sorted_map.begin()->second;
        sorted_map.erase(sorted_map.begin());
        p = p->next;
        //todo 进一个
        if (p->next)
        {
            sorted_map.insert({p->next->val, p->next});
        }
    }
    return result;
}

// std::vector<vector<int>> combinationSum_(const std::unordered_set<int> &candies, int target)
// {
// }

int main()
{
    // ListNode *p = new ListNode(1);
    // p->next = new ListNode(2);
    // p->next->next = new ListNode(3);
    // p->next->next->next = new ListNode(4);

    ListNode *n1 = new ListNode(1);
    n1->next = new ListNode(4);
    n1->next->next = new ListNode(5);

    ListNode *n2 = new ListNode(1);
    n2->next = new ListNode(3);
    n2->next->next = new ListNode(4);
    // std::cout << search(vec, 3) << std::endl;
    ListNode *n3 = new ListNode(2);
    n3->next = new ListNode(6);

    std::vector<ListNode *> vec = {n1,
                                   n2,
                                   n3};

    ListNode *a = mergeKLists(vec);
    // p = swapPairs(p);
    // while (p)
    // {
    //     std::cout << p->val << '\t';
    //     p = p->next;
    // }
    // std::cout << std::endl;

    return 0;
}
