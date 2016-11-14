#pragma once

#include "Point.h"

class Circle
{
public:
    Circle();
    Circle(const Point &point, int radius);
    Circle(const Circle &other) = default;

    Circle &operator = (const Circle & other) = default;

private:
    Point center_;
    int radius_;
};
