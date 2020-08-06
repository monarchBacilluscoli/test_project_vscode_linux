#include <functional>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Leetcode
{
private:
    // void postorderTraversal_(TreeNode *root, std::vector<int> &result)
    // {
    //     if (root->left)
    //     {
    //         postorderTraversal_(root->left, result);
    //     }
    //     if (root->right)
    //     {
    //         postorderTraversal_(root->right, result);
    //     }
    //     result.push_back(root->val);
    // }

    // const std::vector<std::vector<int>> dirs = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

    // void hitBricks__(std::vector<std::vector<int>> &grid, std::vector<int> &hit, std::unordered_set<std::vector<int>> &brick_set)
    // {
    //     for (int i = 0; i < dirs.size(); ++i)
    //     {
    //         if (hit[0] + dirs[i][0] < grid.size() && hit[0] + dirs[i][0] >= 0 && hit[1] + dirs[i][1] < grid.front().size() && hit[1] + dirs[i][1] >= 0) // 扩展方向有效
    //         {
    //             std::vector<int> point{hit[0] + dirs[i][0], hit[1] + dirs[i][1]};
    //             if (brick_set.find(point) != brick_set.end())
    //             {
    //                 brick_set.emplace(point);
    //             }
    //             hitBricks__(grid, point, brick_set);
    //         }
    //     }
    // }

    // int hitBricks_(std::vector<std::vector<int>> &grid, std::vector<int> &hit)
    // {
    //     std::vector<std::unordered_set<std::vector<int>>> brick_sets(4);
    //     for (int i = 0; i < dirs.size(); ++i)
    //     {
    //         if (hit[0] + dirs[i][0] < grid.size() && hit[0] + dirs[i][0] >= 0 && hit[1] + dirs[i][1] < grid.front().size() && hit[1] + dirs[i][1] >= 0) // 扩展方向有效
    //         {
    //             std::vector<int> point{hit[0] + dirs[i][0], hit[1] + dirs[i][1]};
    //             hitBricks__(grid, point, brick_sets[i]);
    //         }
    //     }

    //     std::set<std::vector<int>> result;
    //     bool safe = false;
    //     for (int i = 0; i < dirs.size(); ++i) // check each set
    //     {
    //         safe = false;
    //         for (auto &i : brick_sets[i])
    //         {
    //             if (i[0] == 0)
    //             {
    //                 safe = true;
    //                 break;
    //             }
    //         }
    //         if (!safe)
    //         {
    //             result.insert(brick_sets[i].begin(), brick_sets[i].end());
    //             // clean those bricks
    //             for (auto &item : brick_sets[i])
    //             {
    //                 grid[item[0]][item[1]] = 0;
    //             }
    //         }
    //     }
    //     return result.size();
    // }

public:
    bool isMatch(std::string s, std::string p)
    {
        size_t m = s.size(), n = p.size();
        std::vector<std::vector<bool>> dp{m + 1, std::vector<bool>(n + 1)};

        dp[0][0] = true;

        for (int i = 1; i <= m; ++i)
        {
            dp[i][0] = false;
        }
        for (int j = 1; j <= n; ++j)
        {
            if (p[j - 1] == '*' && dp[0][j - 1])
            {
                dp[0][j] = true;
            }
            else
            {
                dp[0][j] = false;
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (p[j] <= 'z' && p[j] >= 'a')
                {
                    if (p[j] == s[i] && dp[i][j])
                    {
                        dp[i + 1][j + 1] = true;
                    }
                    else
                    {
                        dp[i + 1][j + 1] = false;
                    }
                }
                else if (p[j] == '?')
                {
                    if (dp[i][j])
                    {
                        dp[i + 1][j + 1] = true;
                    }
                    else
                    {
                        dp[i + 1][j + 1] = false;
                    }
                }
                else if (p[j] == '*')
                {
                    if (dp[i][j] || dp[i][j + 1] || dp[i + 1][j])
                    {
                        dp[i + 1][j + 1] = true;
                    }
                    else
                    {
                        dp[i + 1][j + 1] = false;
                    }
                }
            }
        }
        return dp[m][n];
    }
    // std::vector<int> postorderTraversal(TreeNode *root)
    // {
    //     if (!root)
    //     {
    //         return std::vector<int>{};
    //     }
    //     std::vector<int> result;
    //     postorderTraversal_(root, result);
    //     return result;
    // };

    // int findMin(std::vector<int> &nums)
    // {
    //     if (nums.empty())
    //     {
    //         return 0;
    //     }
    //     int left = 0, right = nums.size() - 1, mid = (left + right) / 2;
    //     while (right - left > 1)
    //     {
    //         mid = (left + right) / 2;
    //         if (nums[mid] > nums[right])
    //         {
    //             left = mid;
    //         }
    //         else if (nums[mid] < nums[right])
    //         {
    //             right = mid;
    //         }
    //     }
    //     return nums[left] > nums[right] ? nums[right] : nums[left];
    // }

    // std::vector<int> hitBricks(std::vector<std::vector<int>> &grid, std::vector<std::vector<int>> &hits)
    // {
    //     std::vector<int> result(hits.size());
    //     for (int i = 0; i < hits.size(); ++i)
    //     {
    //         grid[hits[i][0]][hits[i][1]] = 0;
    //         result[i] = hitBricks_(grid, hits[i]);
    //     }
    //     return result;
    // }

    Leetcode(/* args */) = default;
    ~Leetcode() = default;
};
