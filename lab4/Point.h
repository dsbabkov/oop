#pragma once

#include <iostream>

class Point
{
    friend Point &operator -=(Point &point, int value);
    friend Point operator - (const Point &point);
    friend std::ostream &operator << (std::ostream &os, const Point &point);
public:
    Point();
    explicit Point(int value);
    Point(int x, int y);
    Point(const Point &) = default;

    Point &operator += (const Point &other);
    Point &operator += (int value);
    Point operator + (const Point &other) const;
    Point operator + (int value) const;
    const Point &operator +() const;

    int x() const;
    void setX(int x);

    int y() const;
    void setY(int y);

private:
    int x_;
    int y_;
};

Point &operator-=(Point &first, const Point &second);
Point operator - (Point first, const Point &second);
Point operator - (Point point, int value);
Point operator - (int value, const Point &point);
Point operator + (int value, const Point &point);
Point operator-(const Point &point);
bool operator == (const Point &left, const Point &right);
