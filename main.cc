
#include <iostream>
#include <vector>
#include <map>

enum Dir
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};
const std::map<Dir, std::pair<int, int>> dirs{{Dir::UP, {-1, 0}}, {Dir::DOWN, {1, 0}}, {Dir::LEFT, {0, -1}}, {Dir::RIGHT, {0, 1}}};

void GenerateAToZMtx(std::vector<std::vector<char>> &mtx)
{
    int n = static_cast<int>(mtx.front().size()), m = static_cast<int>(mtx.size()); // m行n列
    int end_x_b = m - 1, end_y_b = n - 1, end_x_t = 1, end_y_t = 0;

    Dir current_dir = Dir::RIGHT;
    int x = 0, y = 0;
    char current_char = 'A';
    while ((end_x_b >= end_x_t || end_y_b >= end_y_t) && x >= 0 && y >= 0 && x < m && y < n)
    {
        mtx[x][y] = current_char;

        switch (current_dir) // 檢查是否hit終點
        {
        case Dir::RIGHT:
            if (y >= end_y_b)
            {
                current_dir = Dir::DOWN;
                --end_y_b;
            }
            break;
        case Dir::LEFT:
            if (y <= end_y_t)
            {
                current_dir = Dir::UP;
                ++end_y_t;
            }
            break;
        case Dir::UP:
            if (x <= end_x_t)
            {
                current_dir = Dir::RIGHT;
                ++end_x_t;
            }
            break;
        case Dir::DOWN:
            if (x >= end_x_b)
            {
                current_dir = Dir::LEFT;
                --end_x_b;
            }
            break;
        default:
            throw(std::runtime_error("no dir"));
        }
        x += (dirs.at(current_dir).first);
        y += (dirs.at(current_dir).second);
        current_char == 'Z' ? (current_char = 'A') : (current_char++);
    }
}

int main(int argc, char **argv)
{
    int m, n;
    std::cin >> m >> n;

    if (m == 0 || n == 0)
    {
        return 0;
    }

    std::vector<std::vector<char>> mtx(m, std::vector<char>(n));

    GenerateAToZMtx(mtx);

    for (auto &&i : mtx)
    {
        for (auto &&j : i)
        {
            std::cout << j << ' ' << std::flush;
        }
        std::cout << std::endl;
    }

    return 0;
}
