#pragma once

class Counter
{
public:
    Counter(const char * str = "", Counter *before = nullptr);
    ~Counter();

    void addOwner();
    void removeOwner();

    const char *str() const;

private:
    Counter *next_;
    char *str_;
    unsigned owners_;
};
