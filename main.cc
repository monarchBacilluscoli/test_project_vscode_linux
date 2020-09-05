
// #pragma pack(push)
// #pragma pack(1)

#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>
// #include <math.h>
#include <numeric>
#include <limits>
#include <algorithm>
#include <random>
#include <map>
#include <stack>
#include <unordered_set>
#include <set>
// #include <malloc.h>
// #include <semaphore.h>
// #include <pthread.h>
// #include <CivetServer.h>
// #include <thread>
// #include <string.h>
#include <list>

// #include "test_function.h"

class VendingMachine
{
private:
    const std::vector<int> m_costs;
    std::vector<std::stack<int>> m_cargos;
    uint m_total_costs = 0;
    bool is_opened = false;

public:
    VendingMachine(const std::vector<int> &costs) : m_costs(costs), m_cargos(costs.size()) {}

    void Open()
    {
        if (is_opened)
        {
            throw("?" + std::string(__FUNCTION__));
        }
        m_total_costs = 0;
        is_opened = true;
    }

    int Close()
    {
        if (!is_opened)
        {
            throw("?" + std::string(__FUNCTION__));
        }
        is_opened = false;
        int cost = m_total_costs;
        m_total_costs = 0;
        return cost;
    }

    void Return(int cargo_num, int good_num)
    {
        --cargo_num;
        --good_num;
        if (!is_opened)
        {
            throw("please open the vending first" + std::string(__FUNCTION__));
        }
        // 进货
        m_cargos[cargo_num].push(good_num);
        // 算钱
        m_total_costs -= m_costs[good_num];
    }

    int Take(int cargo_num)
    {
        --cargo_num;
        if (!is_opened)
        {
            throw("please open the vending first" + std::string(__FUNCTION__));
        }
        int goods;
        if (m_cargos[cargo_num].empty())
        {
            // 出货
            goods = cargo_num;
        }
        else
        {
            // 出货
            goods = m_cargos[cargo_num].top();
            m_cargos[cargo_num].pop();
        }
        m_total_costs += m_costs[goods];
        return ++cargo_num;
    }

    ~VendingMachine() = default;
};

enum class Hand
{
    LEFT,
    RIGHT
};

class Customer
{
private:
    int m_left = 0;
    int m_right = 0;
    std::list<int> m_goods;

public:
    Customer(/* args */) = default;
    ~Customer() = default;

    void Take(int goods_num, Hand h)
    {
        if (h == Hand::LEFT)
        {
            if (m_left != 0)
            {
                throw("there is a goods in your current hand@" + std::string(__FUNCTION__));
            }
            m_left = goods_num;
        }
        else
        {
            if (m_right != 0)
            {
                throw("there is a goods in your current hand@" + std::string(__FUNCTION__));
            }
            m_right = goods_num;
        }
    }

    int GetLeftHand(Hand h)
    {
        int goods;
        if (h == Hand::LEFT)
        {
            goods = m_left;
            m_left = 0;
        }
        else
        {
            goods = m_right;
            m_right = 0;
        }
        return goods;
    }

    void Keep(Hand h)
    {
        if (h == Hand::LEFT)
        {
            if (m_left == 0)
            {
                throw("no goods in your left hand@" + std::string(__FUNCTION__));
            }
            m_goods.push_back(m_left);
            m_left = 0;
        }
        else
        {
            if (m_right == 0)
            {
                throw("no goods in your right hand@" + std::string(__FUNCTION__));
            }
            m_goods.push_back(m_right);
            m_right = 0;
        }
    }
};

int main(int argc, char **argv)
{
    int cargo_size, customer_size;
    std::cin >> cargo_size >> customer_size;
    std::vector<int> total_costs(customer_size);
    std::vector<int> cargo_costs(cargo_size);
    for (size_t i = 0; i < cargo_size; ++i)
    {
        scanf("%d", &cargo_costs[i]);
    }

    VendingMachine vm(cargo_costs);

    for (size_t i = 0; i < customer_size; ++i)
    {
        Customer c;
        vm.Open();
        int op_size;
        scanf("%d", &op_size);
        for (size_t j = 0; j < op_size; ++j)
        {
            std::string op, hand, cargo_num;
            std::cin >> hand >> op;
            if (op != "keep")
            {
                std::cin >> cargo_num;
            }

            if (hand == "left")
            {
                if (op == "take")
                {
                    c.Take(vm.Take(std::stoi(cargo_num)), Hand::LEFT);
                }
                else if (op == "return")
                {
                    vm.Return(std::stoi(cargo_num), c.GetLeftHand(Hand::LEFT));
                }
                else if (op == "keep")
                {
                    c.Keep(Hand::LEFT);
                }
            }
            else
            {
                if (op == "take")
                {
                    c.Take(vm.Take(std::stoi(cargo_num)), Hand::RIGHT);
                }
                else if (op == "return")
                {
                    vm.Return(std::stoi(cargo_num), c.GetLeftHand(Hand::RIGHT));
                }
                else if (op == "keep")
                {
                    c.Keep(Hand::RIGHT);
                }
            }
        }
        total_costs[i] = vm.Close();
    }

    for (int i : total_costs)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
