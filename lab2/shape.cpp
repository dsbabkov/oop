#include "shape.h"
#include <iostream>
#include "rect.h"

Shape::Shape(Color color)
    : color_{color}
{

}

Shape::Shape(const Shape &other)
    : color_{other.color_}
{
}

Shape::Shape(const Rect &rect)
    : color_{rect.color_}
{
}

Shape::~Shape()
{
}

Shape::Color Shape::color() const
{
    return color_;
}

void Shape::setColor(const Color &color)
{
    color_ = color;
}

void Shape::WhereAmI() const
{
    std::cout << "Now I am in class " << className() << '\n';
}

const char *Shape::className() const
{
    return "Shape";
}

