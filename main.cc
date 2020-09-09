
#include <string>
#include <iostream>
#include <vector>

// from (i,j) check word[w];
bool extend(std::vector<std::vector<char>> &mtx, const std::string &word, int i, int j, int w)
{
    int x_sz = mtx.front().size(), y_sz = mtx.size();
    if (i < 0 || j < 0 || i >= y_sz || j >= x_sz)
    {
        return false;
    }
    else
    {
        // if all the checks from here false, set the value to 0;
        if (word[w] == mtx[i][j])
        {
            if (w == word.size() - 1)
            {
                return true;
            }
            else
            {
                mtx[i][j] = 0;
                if (extend(mtx, word, i - 1, j, w + 1) ||
                    extend(mtx, word, i + 1, j, w + 1) ||
                    extend(mtx, word, i, j - 1, w + 1) ||
                    extend(mtx, word, i, j + 1, w + 1))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
    }
}
std::vector<std::vector<char>> g_matrix = {
    {'A', 'B', 'C', 'E'},
    {'S', 'F', 'C', 'S'},
    {'A', 'D', 'E', 'E'}};

bool WordCheck(const std::vector<std::vector<char>> &board, const std::string &word)
{
    int x_sz = board.front().size(), y_sz = board.size();
    for (size_t i = 0; i < y_sz; ++i)
    {
        for (size_t j = 0; j < x_sz; ++j)
        {
            std::vector<std::vector<char>> bd = board;
            if (extend(bd, word, i, j, 0))
            {
                return true;
            }
        }
    }

    return false;
}

int main(int argc, char **argv)
{
    std::cout << 79 / 20 << std::endl;

    std::string s;
    std::cin >> s;

    std::cout << (WordCheck(g_matrix, s) ? "true" : "false") << std::endl;

    return 0;
}
