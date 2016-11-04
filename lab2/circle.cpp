#include "circle.h"
#include "rect.h"

Circle::Circle(Color color, double radius)
    : Shape{color}
    , radius_{radius}
{
    setColor(color);
}

Circle::Circle(const Rect &rect)
    : Shape{rect}
    , radius_{rect.diagonal() / 2}
{
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


void Circle::Inflate(int value)
{
    radius_ += value;
}
