#pragma once

#include "bin.h"
#include "oct.h"
#include "hex.h"

#include <cstddef>


union MyByte
{
    MyByte(char byte);

    void ShowHex() const;
    void ShowBin() const;
    void ShowOct() const;
    void ShowChar() const;

    void printBit(size_t n) const;
    void setBit(size_t n, bool = true);

    void printHexDigit(size_t n) const;
    void setHexDigit(size_t n, char value);

    void printOctDigit(size_t n) const;
    void setOctDigit(size_t n, char value);

private:
    Bin bin_;
    Oct oct_;
    Hex hex_;
    char byte_;
};
