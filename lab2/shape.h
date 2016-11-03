#pragma once


class Shape
{
public:
    enum Color{Black, Red, Green, Blue};

public:
    explicit Shape(Color = Black);
    virtual ~Shape();

    Color color() const;
    void setColor(const Color &color);

    void WhereAmI() const;

private:
    virtual const char *className() const;

private:
    Color color_;
};
