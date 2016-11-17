#pragma once

#include "Counter.h"

class MyString
{
public:
    MyString(const char *str = "");
    MyString(const MyString &other);
    MyString(MyString &&other);

    MyString &operator = (const MyString &other);
    MyString &operator = (MyString &&other);

private:

};
