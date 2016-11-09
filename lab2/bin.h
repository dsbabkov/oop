#pragma once
#include <stddef.h>

class Bin
{
    friend union MyByte;

private:
    void show() const;
    bool bit(size_t n) const;
    void showBit(size_t n) const;
    void setBit(size_t n, bool = true);

private:
    bool bit_0: 1;
    bool bit_1: 1;
    bool bit_2: 1;
    bool bit_3: 1;
    bool bit_4: 1;
    bool bit_5: 1;
    bool bit_6: 1;
    bool bit_7: 1;

};

