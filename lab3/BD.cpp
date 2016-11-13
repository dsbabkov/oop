#include "BD.h"
#include "DataPair.h"
#include <exception>

BD::BD()
    : first_{}
{
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

std::ostream &operator <<(std::ostream &os, const BD &bd)
{
    os << "Name\tProfession\tSex\tAge\tSalary\n";

    for (const DataPair *it = bd.cbegin(); it; it = it->next()){
        os << *it << "\n";
    }

    return os;
}
