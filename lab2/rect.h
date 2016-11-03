#pragma once

#include "shape.h"

class Rect: public Shape
{
public:
    explicit Rect(Color = Black, double width_ = 1, double height_ = 1);

    double width() const;
    void setWidth(double width);

    double height() const;
    void setHeight(double height);

private:
    virtual const char *className() const override;

private:
    double width_;
    double height_;
};
