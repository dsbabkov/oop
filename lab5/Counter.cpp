#include "Counter.h"
#include <cstring>

Counter::Counter(const char * str, Counter *before)
    : next_{}
    , str_{new char[strlen(str) + 1]}
    , owners_{1}
{
    if (before){
        next_ = before->next_;
        before->next_ = this;
    }

    strcpy(str_, str);
}

Counter::~Counter()
{
    delete[] str_;
}

void Counter::addOwner()
{
    ++owners_;
}

void Counter::removeOwner()
{
    --owners_;
}

const char *Counter::str() const
{
    return str_;
}

Counter &Counter::operator ++(int)
{
    addOwner();
    return *this;
}

Counter &Counter::operator --(int)
{
    removeOwner();
    return *this;
}

Counter Counter::operator ++()
{
    addOwner();
    return *this;
}

Counter Counter::operator --()
{
    removeOwner();
    return *this;
}
