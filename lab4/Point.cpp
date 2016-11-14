#include "Point.h"

Point operator -(const Point &point)
{
    return {-point.x_, -point.y_};
}

std::ostream &operator <<(std::ostream &os, const Point &point)
{
    return os << '{' << point.x_ << "; " << point.y_ << '}';
}

Point::Point()
    : x_{}
    , y_{}
{   
}

Point::Point(int value)
    : x_{value}
    , y_{value}
{
}

Point::Point(int x, int y)
    : x_{x}
    , y_{y}
{
}

Point &Point::operator +=(const Point &other)
{
    x_ += other.x_;
    y_ += other.y_;

    return *this;
}

Point &Point::operator +=(int value)
{
    x_ += value;
    y_ += value;

    return *this;
}

Point Point::operator +(const Point &other) const
{
    return Point(*this) += other;
}

Point Point::operator +(int value) const
{
    return {x_ + value, y_ + value};
}

const Point &Point::operator +() const
{
    return *this;
}

int Point::x() const
{
    return x_;
}

void Point::setX(int x)
{
    x_ = x;
}

int Point::y() const
{
    return y_;
}

void Point::setY(int y)
{
    y_ = y;
}

Point &operator -=(Point &point, int value)
{
    return point += -value;
}

Point &operator-=(Point &first, const Point &second)
{
    first.setX(first.x() - second.x());
    first.setY(first.y() - second.y());
    return first;
}

Point operator -(Point first, const Point &second)
{
    return first -= second;
}

Point operator -(Point point, int value)
{
    return point -= value;
}

Point operator -(int value, const Point &point)
{
    return Point(value) - point;
}

Point operator +(int value, const Point &point)
{
    return point + value;
}
