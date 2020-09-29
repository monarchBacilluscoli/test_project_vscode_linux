
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <cstring>

int main(int argc, char **argv)
{
    int start, end;
    int test = std::numeric_limits<int>::max();
    std::cin >> start >> end;
    test = test << (31 - end);
    test = test >> (31 - end + start);
    test = test << (start);
    std::cout << test << std::endl;

    std::map<int, int> mmm = {{1, 2}, {2, 3}};
    mmm = {{3, 4}};

    

    return 0;
}
