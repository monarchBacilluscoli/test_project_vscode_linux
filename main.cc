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

string longestCommonPrefix(vector<string> &strs)
{
    if (strs.size() == 0)
    {
        return "";
    }
    if (strs.size() == 1)
    {
        return strs.front();
    }
    string prefix = "";
    bool eq = true;
    int comp_index = 0;
    
    while (eq)
    {
        char comp_char = strs[0][comp_index];
        for (int i = 1; i < strs.size(); i++)
        {
            if (strs[i][comp_index] != comp_char)
            {
                eq = false;
                break;
            }
        }
        comp_index++;
    }
}

int main(int argc, char *argv[])
{
    std::vector<string> v = {"flower", "flow", "flight"};
    std::cout << longestCommonPrefix(v) << std::endl;
    return 0;
}
