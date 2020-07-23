
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
#include <unordered_set>
#include <set>

#include "test_function.h"

using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(NULL) {}
// };


std::vector<std::unordered_set<char>> rows{9};
std::vector<std::unordered_set<char>> columns{9};
std::vector<std::unordered_set<char>> blocks{9};
bool isValidSudoku(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (board[i][j] != '.')
            {
                char current = board[i][j];
                if (rows[i].find(current) == rows[i].end())
                {
                    rows[i].insert(current);
                }
                else
                {
                    return false;
                }

                if (columns[j].find(current) == columns[j].end())
                {
                    columns[j].insert(current);
                }
                else
                {
                    return false;
                }
                int block_index = (i / 3) * 3 + j / 3;
                if (blocks[block_index].find(current) == blocks[block_index].end())
                {
                    blocks[block_index].insert(current);
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    // ListNode *p = new ListNode(1);
    // p->next = new ListNode(2);
    // p->next->next = new ListNode(3);
    // p->next->next->next = new ListNode(4);
    std::vector<std::vector<char>> vec{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    std::cout << isValidSudoku(vec) << std::endl;

    // std::cout << search(vec, 3) << std::endl;

    // p = swapPairs(p);
    // while (p)
    // {
    //     std::cout << p->val << '\t';
    //     p = p->next;
    // }
    // std::cout << std::endl;

    return 0;
}
