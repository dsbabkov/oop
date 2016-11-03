#pragma once

#include "shape.h"

class Rect;

class Circle: public Shape
{
public:
    Circle(Color = Black, double radius = 1);
    explicit Circle(const Rect &rect);

    double radius() const;
    void setRadius(double radius);

private:
    virtual const char *className() const override;

private:
    double radius_;
};
