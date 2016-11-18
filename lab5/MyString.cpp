#include "MyString.h"
#include "Counter.h"

Counter *MyString::counters_ = {};

MyString::MyString(const char *str)
    : counter_{counterForString(str)}
{
    counter_->addOwner();
}

MyString::MyString(const MyString &other)
    : counter_{other.counter_}
{
    counter_->addOwner();
}

MyString::MyString(MyString &&other)
    : counter_{other.counter_}
{
    other.counter_ = counterForString("");
    other.counter_->addOwner();
}

MyString::~MyString()
{
    decrementCounter();
}

MyString &MyString::operator = (const MyString &other){
    decrementCounter();
    counter_ = other.counter_;
    counter_->addOwner();
    return *this;
}

MyString &MyString::operator = (MyString &&other){
    decrementCounter();
    counter_ = other.counter_;
    other.counter_ = counterForString("");
    other.counter_->addOwner();
    return *this;
}

MyString &MyString::operator = (const char *str)
{
    decrementCounter();
    counter_ = counterForString(str);
    counter_->addOwner();
    return *this;
}

const char *MyString::cStr() const
{
    return counter_->str();
}

void MyString::decrementCounter()
{
    counter_->removeOwner();
    if (!counter_->hasOwners()){
        deleteCounter(counter_);
        counter_ = {};
    }
}

Counter *MyString::counterForString(const char *str)
{
    if (!counters_){
        counters_ = new Counter(str);
        return counters_;
    }

    for(Counter *p = counters_; p; p = p->next()){
        if (*p == str){
            return p;
        }
    }

    return new Counter(str, counters_);
}

void MyString::deleteCounter(Counter *counter)
{
    if (counter == counters_){
        counters_ = counters_->next();
    }
    else{
        excludeCounterFromList(counter);
    }

    delete counter;
}

void MyString::excludeCounterFromList(Counter *counter)
{
    for (Counter *p = counters_; p; p = p->next()){
        if (p->next() == counter){
            p->setNext(counter->next());
            break;
        }
    }

    counter->setNext({});
}

void MyString::toggleStringsCase()
{
    for (Counter *p = counters_; p; p = p->next()){
        p->toggleStringCase();
    }
}

void MyString::printAllStrings()
{
    if (!counters_){
        std::cout << "No strings\n";
    }

    for (const Counter *p = counters_; p; p = p->next()){
        std::cout << "String: " << p->str() << " Copies: " << p->owners() << '\n';
    }
}

void MyString::debugPrintCountersCount()
{
    unsigned result = 0;
    for (const Counter *p = counters_; p; p = p->next()){
        ++result;
    }
    std::cout << "Counters count = " << result << '\n';
}

std::ostream & operator << (std::ostream &os, const MyString &str){
    return os << str.cStr();
}
