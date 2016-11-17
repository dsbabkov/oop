#pragma once

class Counter
{
    Counter(const Counter &other) = delete;
    Counter &operator = (const Counter &ohter) = delete;

public:
    Counter(const char * str = "", Counter *before = nullptr);
    ~Counter();

    void addOwner();
    void removeOwner();

    const char *str() const;

    Counter &operator ++(int);
    Counter &operator --(int);
    Counter operator ++();
    Counter operator --();

private:
    Counter *next_;
    char *str_;
    unsigned owners_;
};
