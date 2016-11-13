#pragma once
#include "myString.h"

struct Data
{
    unsigned char age;
    enum Sex {Male, Female} sex;
    MyString profession;
    double salary;
};
