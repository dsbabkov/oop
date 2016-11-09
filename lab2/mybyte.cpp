#include "mybyte.h"
#include <iostream>

MyByte::MyByte(char byte)
    : byte_{byte}
{
}

void MyByte::ShowHex() const
{
    hex_.show();
}

void MyByte::ShowBin() const
{
    bin_.show();
}

void MyByte::ShowOct() const
{
    oct_.show();
}

void MyByte::ShowChar() const
{
    std::cout << byte_ << '\n';
}

void MyByte::printBit(size_t n) const
{
    bin_.showBit(n);
}

void MyByte::setBit(size_t n, bool)
{
    bin_.setBit(n);
}

void MyByte::printHexDigit(size_t n) const
{

}

void MyByte::setHexDigit(size_t n, char value)
{

}

void MyByte::printOctDigit(size_t n) const
{

}

void MyByte::setOctDigit(size_t n, char value)
{

}
