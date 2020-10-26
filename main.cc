
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <cstring>
#include <bitset>
#include <set>
#include <numeric>

uint32_t CoverBits(uint32_t &src, uint32_t tar, uint16_t start, uint16_t size)
{
    uint16_t end = start + size;
    uint32_t mask = std::numeric_limits<uint32_t>::max();
    std::cout << std::bitset<32>(mask) << std::endl;
    mask << (32 - end - 1);
    mask >> (32 - end - 1);
    mask >> start;
    std::cout << std::bitset<32>(mask) << std::endl;
    mask << start;

    return tar;
}

int checkpsw(std::string password)
{
    std::vector<int> constrints(4); // 大写，小写，数字，其他符号
    int sz = password.size();
    if (sz < 8)
    {
        return 1;
    }
    std::set<std::vector<char>> s;
    for (int i = 0; i < sz - 1; ++i)
    {
        std::vector<char> pair{password[i], password[i + 1]};
        if (s.find(pair) != s.end())
        {
            return 1;
        }
        else
        {
            s.insert(pair);
        }
        char c = password[i];
        if (isupper(c) && !(constrints[0]))
        {
            constrints[0] = 1;
        }
        else if (islower(c) && !(constrints[1]))
        {
            constrints[1] = 1;
        }
        else if (isdigit(c) && !(constrints[2]))
        {
            constrints[2] = 1;
        }
        else if (!(constrints[3]))
        {
            constrints[3] = 1;
        }
    }
    if (std::accumulate(constrints.begin(), constrints.end(), 0) < 3)
    {
        return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    uint32_t a, b;
    uint start, size;
    // std::cin >> a >> b >> start >> size;
    // CoverBits(a, b, start, size);

    uint t = 111;
    int t1 = -t;
    float t2 = -t;
    auto tt = sizeof(t);
    auto tt1 = sizeof(t2);

    return 0;
}
