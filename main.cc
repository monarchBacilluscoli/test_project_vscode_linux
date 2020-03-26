#include <iostream>
#include <map>
#include <string>
#include <typeinfo>
#include <limits>

struct Point2D
{
    float x, y;
};

float CalcuSlope(const Point2D &p1, const Point2D &p2)
{
    float denominator = p2.x - p1.x;
    if (denominator != 0.f)
    {
        return (p2.y - p1.y) / (p2.x - p1.x);
    }
    else
    {
        return std::numeric_limits<float>::max(); // 正负最大其实意义都不大了对吧
    }
}

Point2D CalcuFootPoint(const Point2D &p, const Point2D &line_end1, const Point2D &line_end2)
{
    Point2D target_point;
    float k = CalcuSlope(line_end1, line_end1);
    target_point.x = (k * k * line_end1.x + k * (p.y - line_end1.y) + p.x) / (k * k + 1);
    target_point.y = k * (target_point.x - line_end1.x) + line_end1.y;
    return target_point;
}

Point2D CalcuNearestPointOnLine(const Point2D &p, const Point2D &line_end1, const Point2D &line_end2)
{
    Point2D foot_point = CalcuFootPoint(p, line_end1, line_end2);
    if ((foot_point.x - line_end1.x) * (foot_point.x - line_end2.x) <= 0.f) // if the foot is on the line
    {
        return foot_point;
    }
    else
    {
        if ((foot_point.x - line_end1.x) / (foot_point.x - line_end2.x) < 1.f) // denominator will not be 0
        {
            return line_end1;
        }
        else
        {
            return line_end2;
        }
    }
}

int main()
{
    // todo 求到线段上的最短距离.
    // todo 先求垂足吧
    Point2D p1{0, 0};
    Point2D p2{2, 0};
    Point2D p{0, 1};
    float k = CalcuSlope(p1, p2);
    float x = (k * k * p1.x + k * (p.y - p1.y) + p.x) / (k * k + 1);
    float y = k * (x - p1.x) + p1.y;
    std::map<int, bool> test_map{{1, false}, {2, true}};
    for (std::pair<const int, bool> &i : test_map)
    {
        std::cout << typeid(i.second).name() << std::endl;
        break;
    }

    std::cout << "Hello, world!" << std::endl;
    return 0;
}