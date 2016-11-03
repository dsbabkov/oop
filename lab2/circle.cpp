#include "circle.h"

Circle::Circle(Color color, double radius)
    : Shape{color}
    , radius_{radius}
{
    setColor(color);
}

const char *Circle::className() const
{
    return "Circle";
}

double Circle::radius() const
{
    return radius_;
}

void Circle::setRadius(double radius)
{
    radius_ = radius;
}

