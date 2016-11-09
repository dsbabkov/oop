#pragma once
#include <cstddef>

class Hex
{
    friend union MyByte;

private:
    void show() const;
    void showDigit(size_t n) const;
    void setDigit(size_t n, char value) const;
    void printDecDigit(unsigned digit) const;

private:
    unsigned right_: 4;
    unsigned left_: 4;
};
