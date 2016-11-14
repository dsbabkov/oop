#include "circle.h"

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

