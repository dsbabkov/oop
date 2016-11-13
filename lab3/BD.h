#pragma once

#include "Data.h"
#include <iostream>

class DataPair;

class BD
{
public:
    BD();
    ~BD();

    DataPair *find(const MyString &name);
    const DataPair *find(const MyString &name) const;
    Data &operator [] (const MyString &name);
    const Data &operator [] (const MyString &name) const;
    bool erase(const MyString &name);

    const DataPair *cbegin() const;

private:
    DataPair *first_;
    DataPair *last_;
};

std::ostream &operator << (std::ostream &os, const BD &bd);
