#include "shape.h"
#include <iostream>

Shape::Shape(Color color)
    : color_{color}
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

