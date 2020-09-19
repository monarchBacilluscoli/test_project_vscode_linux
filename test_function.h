#include <functional>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <mutex>
#include <thread>

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

    int maxSubArray(std::vector<int> &nums)
    {
        int sz = nums.size();
        std::vector<std::vector<int>> dp(sz, std::vector<int>(sz));
        dp[0][0] = nums[0];
        int max = dp[0][0];
        for (int i = 0; i < sz; ++i)
        {
            for (int j = i; j < sz; ++j)
            {
                dp[i][j] = dp[i][j - 1] + nums[j];
                if (dp[i][j] > max)
                {
                    max = dp[i][j];
                }
            }
        }
        return max;
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

class A
{
public:
    A() { Hi(); }
    virtual void Hi();
    virtual void Oh() { std::cout << "Oh A" << std::endl; }

    virtual ~A() { Hi(); }
};

class B : public A
{
public:
    B() { Hi(); }
    virtual void Hi() { std::cout << "B" << std::endl; }
    virtual void Oh() { std::cout << "Oh B" << std::endl; }
    virtual ~B() { Hi(); }
};

class C : public B
{
private:
    char a = 1;

public:
    C() { Hi(); }
    virtual void Hi() { std::cout << "C" << std::endl; }
    virtual void Oh() { std::cout << "Oh C" << std::endl; }
    virtual ~C() { Hi(); }
};

class ReaderWriterProblem
{
private:
    std::vector<int> m_fiction_chapters;

    std::vector<std::thread> m_reader_threads;

    std::thread m_w_thread;

    int m_current_reader_count = 0;
    std::vector<bool> m_reader_has_read;
    const int m_total_reader_count;

    std::mutex m_count_mtx;
    std::mutex m_finction_mtx;

public:
    ReaderWriterProblem(int reader_count) : m_total_reader_count(reader_count), m_reader_has_read(reader_count){};

    void Run()
    {
        for (size_t i = 0; i < m_total_reader_count; ++i)
        {
            m_reader_threads.push_back(std::thread(&ReaderWriterProblem::Read, this, i));
        }
        Write();
    }

    void Write()
    {
        while (1)
        {
            std::lock_guard<std::mutex> lg(m_count_mtx);
            //写一个章节
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            size_t current_chapter = m_fiction_chapters.size();
            m_fiction_chapters.push_back(current_chapter);
            std::cout << "chapter " << current_chapter << std::endl;
        }
    }

    void Read(int index) //todo 每一个reader不能读第二遍
    {
        static int current_chapter = 0;
        while (1)
        {
            m_count_mtx.lock();              //读也敏感的数据，先不要读，先锁
            if (m_current_reader_count == 0) // 第一个进来拿到数据的先锁上写锁
            {
                m_finction_mtx.lock();
            }
            ++m_current_reader_count;
            m_count_mtx.unlock();

            if (current_chapter)
                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
            std::cout << m_fiction_chapters.back() << std::endl;

            m_count_mtx.lock(); //读也敏感的数据，先不要读，先锁
            --m_current_reader_count;
            if (m_current_reader_count == 0)
            {
                m_finction_mtx.unlock();
            }
            m_count_mtx.unlock();
        }
    }

    ~ReaderWriterProblem();
};
