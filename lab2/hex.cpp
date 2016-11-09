#include "hex.h"
#include <iostream>
#include <cassert>

void Hex::show() const
{
    std::cout << "0x";
    printDecDigit(left_);
    printDecDigit(right_);
    std::cout << '\n';
}

void Hex::showDigit(size_t n) const
{
    switch (n) {
    case 0:
        printDecDigit(right_);
        break;
    case 1:
        printDecDigit(left_);
    default:
        std::cout << "Wrong digit number";
        break;
    }
}

void Hex::setDigit(size_t n, char value) const
{
//    if (!(0 <= value && value <= 15))
}

void Hex::printDecDigit(unsigned digit) const
{

    if(digit < 16){
        static const char* abc = "0123456789ABCDEF";
        std::cout << abc[digit];
    }
    else{
        std::cout << "Wrong @!";
    }
}
