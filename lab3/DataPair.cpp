#include "DataPair.h"

DataPair::DataPair(const MyString &name)
    : name_{name}
    , data_{}
    , next_{}
    , prev_{}
{
}

const MyString &DataPair::name() const
{
    return name_;
}

MyString &DataPair::name()
{
    return name_;
}

void DataPair::setName(const MyString &name)
{
    name_ = name;
}

const Data &DataPair::data() const
{
    return data_;
}

Data &DataPair::data()
{
    return data_;
}

void DataPair::setData(const Data &data)
{
    data_ = data;
}

const DataPair *DataPair::next() const
{
    return next_;
}

std::ostream &operator <<(std::ostream &os, const DataPair &pair)
{
    const Data &data = pair.data();
    return os << pair.name() << "\t"
       << data.profession << "\t\t"
       << (data.sex ? "Female" : "Male") << "\t"
       << static_cast<int>(data.age) << "\t"
       << data.salary;
}
