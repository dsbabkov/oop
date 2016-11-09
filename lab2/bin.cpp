#include "bin.h"
#include <iostream>

void Bin::show() const
{
    for (size_t i = 7; i < 8; --i){
        std::cout << bit(i);
    }
    std::cout << '\n';
}

bool Bin::bit(size_t n) const
{
    if ( n >= 8 ){
        std::cout << "Wrong bit number";
        return false;
    }

    const bool bitarray[] = {
        bit_0,
        bit_1,
        bit_2,
        bit_3,
        bit_4,
        bit_5,
        bit_6,
        bit_7
    };

    return bitarray[n];
}

void Bin::showBit(size_t n) const
{
    std::cout << bit(n) << '\n';
}

void Bin::setBit(size_t n, bool ok)
{
    if ( n >= 8 ){
        std::cout << "Wrong bit number";
        return;
    }

    bool bitarray[] = {
            bit_0,
            bit_1,
            bit_2,
            bit_3,
            bit_4,
            bit_5,
            bit_6,
            bit_7
        };
    bitarray[n] = ok;

    bit_0 = bitarray[0];
    bit_1 = bitarray[1];
    bit_2 = bitarray[2];
    bit_3 = bitarray[3];
    bit_4 = bitarray[4];
    bit_5 = bitarray[5];
    bit_6 = bitarray[6];
    bit_7 = bitarray[7];
}
