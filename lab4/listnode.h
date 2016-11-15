#pragma once

#include "circle.h"

class ListNode
{
    ListNode(const ListNode &) = delete;
    ListNode &operator = (const ListNode &) = delete;
    ListNode &operator = (ListNode &&) = delete;

public:
    ListNode();
    ListNode(ListNode &&other);
    ListNode(ListNode *after, const Circle &circle);
    ~ListNode();

    Circle &data();
    const Circle &data() const;

    ListNode *prev() const;
    ListNode *next() const;

    void setPrev(ListNode *prev);
    void setNext(ListNode *next);

    void swap(ListNode &other);
    void swapData(ListNode &other);

private:
    ListNode *prev_;
    ListNode *next_;
    Circle data_;
};
