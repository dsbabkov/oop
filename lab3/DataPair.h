#pragma once

#include <iostream>
#include "Data.h"

class DataPair
{
    friend class BD;

public:
    DataPair() = delete;
    explicit DataPair(const MyString &name);

    const MyString &name() const;
    MyString &name();
    void setName(const MyString &name);

    const Data &data() const;
    Data &data();
    void setData(const Data &data);

    const DataPair *next() const;

private:
    MyString name_;
    Data data_;
    DataPair *next_;
    DataPair *prev_;
};

std::ostream &operator << (std::ostream &os, const DataPair &pair);
