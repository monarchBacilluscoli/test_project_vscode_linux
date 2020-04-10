#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <limits>
#include <math.h>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>

#include "test_function.h"

struct Point2D
{
    float x, y;

    Point2D operator-(const Point2D &rhs)
    {
        return Point2D{this->x - rhs.x, this->y - rhs.y};
    }
};

float Distance2D(const Point2D &p1, const Point2D &p2)
{
    return std::pow(pow(p2.y - p1.y, 2) + std::pow(p2.x - p1.x, 2), .5f);
}

float CalcuSlope(const Point2D &p1, const Point2D &p2)
{
    float denominator = p2.x - p1.x;
    if (denominator != 0.f)
    {
        return (p2.y - p1.y) / (p2.x - p1.x);
    }
    else
    {
        return std::numeric_limits<float>::max(); // 无论是竖线还是长度0都是这样
    }
}

Point2D CalcuFootPoint(const Point2D &p, const Point2D &line_end1, const Point2D &line_end2)
{

    if (line_end2.x - line_end1.x == 0.f) // 平行y轴
    {
        if (line_end2.y - line_end1.y == 0.f)
        {
            throw(std::string("The two points can not make a line segment") + __FUNCTION__);
        }
        else
        {
            return Point2D{line_end1.x, p.y};
        }
    }
    else
    {
        Point2D target_point;
        float k = CalcuSlope(line_end1, line_end2);
        target_point.x = (k * k * line_end1.x + k * (p.y - line_end1.y) + p.x) / (k * k + 1);
        target_point.y = k * (target_point.x - line_end1.x) + line_end1.y;
        return target_point;
    }
}

Point2D CalcuNearestPointOnLine(const Point2D &p, const Point2D &line_end1, const Point2D &line_end2)
{
    Point2D foot_point = CalcuFootPoint(p, line_end1, line_end2);
    if ((foot_point.x - line_end1.x) * (foot_point.x - line_end2.x) < 0.f || (foot_point.y - line_end1.y) * (foot_point.y - line_end2.y) < 0.f) // if the foot is on the line
    {
        return foot_point;
    }
    else
    {
        if (Distance2D(p, line_end1) < Distance2D(p, line_end2)) // denominator will not be 0
        {
            return line_end1;
        }
        else
        {
            return line_end2;
        }
    }
}

std::vector<int> ReturnAVector(int i)
{
    std::cout << __FUNCTION__ << std::endl;
    return std::vector<int>{i, i, i};
}

float AreaTriangle(const Point2D &p1, const Point2D &p2, const Point2D &p3)
{
    return std::abs((p2.x * p1.y - p1.x * p2.y + p3.x * p2.y - p2.x * p3.y - p3.x * p1.y + p1.x * p3.y) / 2);
}

float DisPointToLine(const Point2D &point, const Point2D &line_end1, const Point2D &line_end2)
{
    return AreaTriangle(point, line_end1, line_end2) * 2 / Distance2D(line_end1, line_end2);
}

// Point2D CalcPointOnLineByRatio(const Point2D &end1, const Point2D &end2, float ratio)
// {
//     Point2D dir = end2 - end1;

// }

const Point2D &FindNearestPointFromPoint(const Point2D &p, std::vector<Point2D> ps)
{
    return *(std::min_element(ps.begin(), ps.end(), [&p](const Point2D &a, const Point2D &b) -> bool { return Distance2D(a, p) < Distance2D(b, p); }));
}

class test
{
private:
    /* data */
public:
    static int test_sta(int a) { return a; };
};

int main(int argc, char *argv[])
{
    std::cout << -34 % 2 << std::endl;
    std::cout << -33 % 2 << std::endl;

    std::vector<int> v = {1, 2, 2, 4};

    test_function<test_sta_func_cla> ts;
    ts.call(test_sta_func_cla::test_func);

    Point2D t{1, 2};
    std::vector<Point2D> ps{{2, 3}, {4, 5}, {1.3f, 1.5f}, {1, 1}, {-2, 1}};
    Point2D p = FindNearestPointFromPoint(t, ps);

    std::list<int> li{1, 2, 3, 4, 5};
    std::cout << std::distance(li.begin(), li.end()) << std::endl;

    std::cout << AreaTriangle(Point2D{3, 4}, Point2D{1, 2}, Point2D{5, 2}) << std::endl;
    std::cout << DisPointToLine(Point2D{3, 4}, Point2D{1, 2}, Point2D{5, 2}) << std::endl;

    //test range for
    int i = 1;
    for (int item : ReturnAVector(i))
    {
        std::cout << item << '\t' << std::flush;
        i++;
    }
    std::cout << std::endl;

    std::map<int, bool> test_m{std::pair<int, bool>{100, true}, std::pair<int, bool>{222, true}};
    if (test_m.find(300) != test_m.end())
    {
        std::cout << test_m[300] << std::endl;
    }
    else
    {
        std::cout << "don't have" << std::endl;
    }

    // todo 求到线段上的最短距离.
    // todo 先求垂足吧
    if (argc == 7)
    {
        Point2D p{std::stof(argv[1]), std::stof(argv[2])};
        Point2D p1{std::stof(argv[3]), std::stof(argv[4])};
        Point2D p2{std::stof(argv[5]), std::stof(argv[6])};
        std::cout << Distance2D(p, p1) << '\t' << Distance2D(p, p2) << std::endl;

        Point2D target = CalcuNearestPointOnLine(p, p1, p2);
        std::cout << target.x << '\t' << target.y << std::endl;
    }

    //
    std::map<int, bool> test_map{{1, false}, {2, true}};
    for (std::pair<const int, bool> &i : test_map)
    {
        std::cout << typeid(i.second).name() << std::endl;
        break;
    }

    std::cout << "Hello, world!" << std::endl;
    return 0;
}