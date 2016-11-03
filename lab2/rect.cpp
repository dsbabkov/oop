#include "rect.h"

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

double Rect::width() const
{
    return width_;
}

void Rect::setWidth(double width)
{
    width_ = width;
}

