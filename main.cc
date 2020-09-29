
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <cstring>
#include <bitset>

uint32_t CoverBits(uint32_t src, uint32_t tar, uint16_t start, uint16_t size)
{
    std::bitset<32> sb(src);
    std::cout << "src:\t" << sb << std::endl;
    std::bitset<32> tb(tar);
    std::cout << "tar:\t" << tb << std::endl;

    for (size_t i = 0; i < size; ++i)
    {
        size_t index = start + i;
        tb[index] = sb[index];
    }
    std::cout << "Cov:\t" << tb << std::endl;
    return tb.to_ulong();
}

int main(int argc, char **argv)
{
    uint32_t a, b;
    uint start, size;
    std::cin >> a >> b >> start >> size;
    CoverBits(a, b, start, size);

    return 0;
}
