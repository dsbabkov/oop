#pragma once
#include "myString.h"

struct Data
{
    enum Sex {Male, Female};
    Data();
    Data(unsigned char age,
         Data::Sex sex,
         const MyString &profession,
         double salary);

    unsigned char age;
    Sex sex;
    MyString profession;
    double salary;
};
