
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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

ListNode *mergeKLists(std::vector<ListNode *> &lists)
{
    std::multimap<int, ListNode *> sorted_map;
    ListNode *result = new ListNode(0), *p = result;
    for (int i = 0; i < lists.size(); ++i)
    {
        if (lists[i])
        {
            sorted_map.insert({lists[i]->val, lists[i]});
        }
    }

    while (!sorted_map.empty())
    {
        //todo 出一个
        p->next = sorted_map.begin()->second;
        sorted_map.erase(sorted_map.begin());
        p = p->next;
        //todo 进一个
        if (p->next)
        {
            sorted_map.insert({p->next->val, p->next});
        }
    }
    return result;
}

vector<TreeNode *> generateTrees_(const std::vector<int> &nums, int start, int size) //左闭又开区间
{
    vector<TreeNode *> results(0);
    if (size <= 0)
    {
        return results;
    }
    else if (size == 1)
    {
        results.push_back(new TreeNode(nums[start]));
        return results;
    }
    else
    {
        for (int i = start; i < start + size; ++i)
        {
            vector<TreeNode *> lefts = generateTrees_(nums, start, i - start);
            vector<TreeNode *> rights = generateTrees_(nums, i + 1, size - (i - start) - 1);
            if (!lefts.empty() && !rights.empty())
            {
                for (int j = 0; j < lefts.size(); ++j) //todo 排列组合，哪怕是0也有null
                {
                    for (int k = 0; k < rights.size(); ++k)
                    {
                        TreeNode *root = new TreeNode(nums[i]);
                        root->left = lefts[j];
                        root->right = rights[k];
                        results.push_back(root);
                    }
                }
            }
            else if (lefts.empty())
            {
                for (int k = 0; k < rights.size(); ++k)
                {
                    TreeNode *root = new TreeNode(nums[i]);
                    root->right = rights[k];
                    results.push_back(root);
                }
            }
            else if (rights.empty())
            {
                for (int j = 0; j < lefts.size(); ++j)
                {
                    TreeNode *root = new TreeNode(nums[i]);
                    root->left = lefts[j];
                    results.push_back(root);
                }
            }
        }
        return results;
    }
}

vector<TreeNode *> generateTrees(int n)
{
    std::vector<int> nums(n);
    std::iota(nums.begin(), nums.end(), 1);
    return generateTrees_(nums, 0, n);
}

bool isValidBST_(TreeNode *root, int upper, int lower)
{
    if (!root)
    {
        return true;
    }
    if (root->val <= lower)
    {
        return false;
    }
    if (root->val >= upper)
    {
        return false;
    }
    return isValidBST_(root->left, root->val, lower) && isValidBST_(root->right, upper, root->val);
}

bool isValidBST(TreeNode *root)
{
    return isValidBST_(root, numeric_limits<int>::max(), numeric_limits<int>::lowest());
}

int main(int argc, char **argv)
{
    // ListNode *p = new ListNode(1);
    // p->next = new ListNode(2);
    // p->next->next = new ListNode(3);
    // p->next->next->next = new ListNode(4);

    // auto results = generateTrees(3);
    
    Leetcode lc;
    // TreeNode *root = new TreeNode(1);
    // root->right = new TreeNode(2);
    // root->right->left = new TreeNode(3);
    // auto a = lc.postorderTraversal(root);

    // std::vector<int> v = {3, 4, 5, 1, 2};
    // auto a = lc.findMin(v);
    // std::vector<std::vector<int>> grid = {{1, 0, 0, 0}, {1, 1, 1, 0}};
    // std::vector<std::vector<int>> hits = {{1, 1}, {1, 0}};
    // auto b = lc.hitBricks(grid, hits);

    // p = swapPairs(p);
    // while (p)
    // {
    //     std::cout << p->val << '\t';
    //     p = p->next;
    // }
    // std::cout << std::endl;

    return 0;
}
