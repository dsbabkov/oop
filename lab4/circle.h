#pragma once

#include "Point.h"

class Circle
{
public:
    Circle();
    Circle(const Point &point, int radius);
    Circle(const Circle &other) = default;

    Circle &operator = (const Circle & other) = default;

    Point center() const;
    void setCenter(const Point &center);

    int radius() const;
    void setRadius(int radius);

    double square() const;

private:
    Point center_;
    int radius_;
};

bool operator == (const Circle &left, const Circle &right);
