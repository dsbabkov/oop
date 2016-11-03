#pragma once

#include "shape.h"

class Circle: public Shape
{
public:
    Circle(Color = Black, double radius = 1);

    double radius() const;
    void setRadius(double radius);

private:
    virtual const char *className() const override;

private:
    double radius_;
};
