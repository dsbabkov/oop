#pragma once

class Rect;

class Shape
{
public:
    enum Color{Black, Red, Green, Blue};

public:
    explicit Shape(Color = Black);
    Shape (const Shape &other);
    Shape (const Rect &rect);
    virtual ~Shape();

    Color color() const;
    void setColor(const Color &color);

    void WhereAmI() const;

private:
    virtual const char *className() const;

private:
    Color color_;
};
