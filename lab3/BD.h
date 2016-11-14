#pragma once

#include "Data.h"
//#include <iostream>

class DataPair;

class BD
{
public:
    BD();
    BD(const BD &other);
    BD(BD &&other);
    ~BD();

    DataPair *find(const MyString &name);
    const DataPair *find(const MyString &name) const;
    Data &operator [] (const MyString &name);
    const Data &operator [] (const MyString &name) const;
    bool erase(const MyString &name);

    const DataPair *cbegin() const;

    void swap(BD &left, BD &right);

    BD &operator = (const BD &other);
    BD &operator = (BD &&other);

private:
    DataPair *first_;
    DataPair *last_;
};

std::ostream &operator << (std::ostream &os, const BD &bd);
