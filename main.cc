
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
const std::unordered_map<char, char> braket_map{{')', '('}, {']', '['}, {'}', '{'}};

bool isValid(std::string s)
{
    std::stack<char> brakets;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (!brakets.empty() && braket_map.find(brakets.top()) != braket_map.end() && s[i] == braket_map.at(brakets.top()))
        {
            brakets.pop();
            s.pop_back();
        }
        else
        {
            brakets.push(s.back());
            s.pop_back();
        }
    }
    if (brakets.empty() && s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::cout << isValid("([)]") << std::endl;
    return 0;
}
