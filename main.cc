
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

//todo 用stack
std::vector<string> results;

void generateParenthesis_(std::string current, int left, int right) // 当前string， 剩余左括号，剩余右括号
{
    if (left > right) //有右括号待填充
    {
        return;
    }
    if (left > 0) // 可以放left
    {
        generateParenthesis_(current + '(', left - 1, right);
    }
    if (right > 0 && right > left) // 可以放right
    {
        generateParenthesis_(current + ')', left, right - 1);
    }
    if (left == 0 && right == 0)
    {
        results.push_back(current);
    }
}

vector<string> generateParenthesis(int n)
{
    generateParenthesis_("", n, n);
    return results;
}

int main()
{
    for (auto &&s : generateParenthesis(3))
    {
        std::cout << s << std::endl;
    }

    return 0;
}
