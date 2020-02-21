#include <iostream>
#include <map>
#include <string>
#include <typeinfo>

int main()
{
    std::map<int, bool> test_map{{1, false}, {2, true}};
    for (std::pair<const int, bool> &i : test_map)
    {
        std::cout << typeid(i.second).name() << std::endl;
        break;
    }

    std::cout << "Hello, world!" << std::endl;
    return 0;
}