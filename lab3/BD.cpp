#include "BD.h"
#include "DataPair.h"
#include <stdexcept>

BD::BD()
    : first_{}
    , last_{}
{
}

BD::BD(const BD &other)
    : first_{}
    , last_{}
{
    const DataPair *it = other.first_;
    while (it){
        operator [](it->name_) = it->data();
        it = it->next_;
    }
}

BD::BD(BD &&other)
    : first_{other.first_}
    , last_{other.last_}
{
    other.first_ = other.last_ = nullptr;
}

BD::~BD()
{
    DataPair *it = first_;
    while (it) {
        DataPair *pair = it;
        it = it->next_;
        delete pair;
    }
}

DataPair *BD::find(const MyString &name)
{
    DataPair *it = first_;
    while(it && it->name() != name){
        it = it->next_;
    }

    return it;
}

const DataPair *BD::find(const MyString &name) const
{
    const DataPair *it = first_;
    while(it && it->name() != name){
        it = it->next_;
    }

    return it;
}

Data &BD::operator [](const MyString &name)
{
    DataPair *pair = find(name);
    if (pair){
        return pair->data();
    }

    DataPair *record = new DataPair(name);
    if (last_){
        record->prev_ = last_;
        last_->next_ = record;
    }
    last_ = record;

    if (!first_){
        first_ = record;
    }

    return record->data();
}

const Data &BD::operator [](const MyString &name) const
{
    const DataPair *pair = find(name);
    if (pair){
        return pair->data();
    }

    throw (std::out_of_range("Bad index got"));
}

bool BD::erase(const MyString &name)
{
    DataPair *pair = find(name);

    if (!pair){
        return false;
    }

    if (pair == first_){
        first_ = pair->next_;
    }

    if (pair == last_){
        last_ = pair->prev_;
    }

    if (pair->next_){
        pair->next_->prev_ = pair->prev_;
    }

    if (pair->prev_){
        pair->prev_->next_ = pair->next_;
    }

    delete pair;

    return true;
}

const DataPair *BD::cbegin() const
{
    return first_;
}

void BD::swap(BD &left, BD &right)
{
    std::swap(left.first_, right.first_);
    std::swap(left.last_, right.last_);
}

BD &BD::operator =(const BD &other)
{
    BD copyOfOther = other;
    swap(*this, copyOfOther);
    return *this;
}

BD &BD::operator =(BD &&other)
{
    first_ = other.first_;
    last_ = other.last_;
    other.first_ = other.last_ = nullptr;

    return *this;
}

std::ostream &operator <<(std::ostream &os, const BD &bd)
{
    os << "Name\tProfession\tSex\tAge\tSalary\n";

    for (const DataPair *it = bd.cbegin(); it; it = it->next()){
        os << *it << "\n";
    }

    return os;
}
