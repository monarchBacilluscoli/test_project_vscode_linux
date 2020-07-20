
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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int divide(int dividend, int divisor)
{
    int op = ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) ? -1 : 1;
    int sum = 0;
    int times = 0;
    dividend = dividend < 0 ? dividend : -dividend;
    divisor = divisor < 0 ? divisor : -divisor;
    while (sum > dividend)
    {
        if (sum < numeric_limits<int>::min() - divisor)
        {
            return numeric_limits<int>::max();
        }
        sum += divisor;
        ++times;
    }
    return (times - 1) * op;
}

int main()
{
    // ListNode *p = new ListNode(1);
    // p->next = new ListNode(2);
    // p->next->next = new ListNode(3);
    // p->next->next->next = new ListNode(4);

    std::cout << divide(-2147483648, -1) << std::endl;

    // p = swapPairs(p);
    // while (p)
    // {
    //     std::cout << p->val << "\t";
    //     p = p->next;
    // }
    // std::cout << std::endl;

    return 0;
}
