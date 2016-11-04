#include "rect.h"
#include <cmath>

Rect::Rect(Color color, double width, double height)
    : Shape{color}
    , width_{width}
    , height_{height}
{
}

const char *Rect::className() const
{
    return "Rect";
}

double Rect::height() const
{
    return height_;
}

void Rect::setHeight(double height)
{
    height_ = height;
}

double Rect::diagonal() const
{
    return sqrt(pow(width_, 2) + pow(height_, 2));
}

double Rect::width() const
{
    return width_;
}

void Rect::setWidth(double width)
{
    width_ = width;
}



void Rect::Inflate(int value)
{
    width_ += value;
    height_ += value;
}
