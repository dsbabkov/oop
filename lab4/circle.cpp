#include "circle.h"
#include <cmath>

static const double pi = acos(-1);

Circle::Circle()
    : center_{}
    , radius_{}
{
}

Circle::Circle(const Point &center, int radius)
    : center_{center}
    , radius_{radius}
{
}

Point Circle::center() const
{
    return center_;
}

void Circle::setCenter(const Point &center)
{
    center_ = center;
}

int Circle::radius() const
{
    return radius_;
}

void Circle::setRadius(int radius)
{
    radius_ = radius;
}

double Circle::square() const
{
    return pi * pow(radius_, 2);
}


bool operator ==(const Circle &left, const Circle &right)
{
    return left.center() == right.center() &&
            left.radius() == right.radius();
}
