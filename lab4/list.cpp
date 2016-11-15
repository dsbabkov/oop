#include "list.h"

List::List()
    : head_{}
    , tail_{ &head_, {} }
    , size_{}
{

}

List::List(const List &other)
    : head_{}
    , tail_{ &head_, {} }
    , size_{other.size_}
{
    for (const ListNode *p = other.head_.next(); p != &other.tail_; p = p->next()){
        append(p->data());
    }
}

List::List(List &&other)
    : head_{std::move(other.head_)}
    , tail_{std::move(other.tail_)}
    , size_{other.size_}
{
    other.head_.setNext(&other.tail_);
    other.tail_.setPrev(&other.head_);
    other.size_ = 0;
}

List::~List()
{
    for (ListNode *p = head_.next(); p != &tail_; p = p->next(), delete p->prev());
}

List &List::operator =(const List &other)
{
    List tmp = other;
    tmp.swap(*this);
    return *this;
}

List &List::operator =(List &&other)
{
    head_.setNext(other.head_.next());
    tail_.setPrev(other.tail_.prev());
    size_ = other.size_;

    other.size_ = 0;
    other.head_.setNext(&other.tail_);
    other.tail_.setPrev(&other.head_);

    return *this;
}

void List::prepend(const Circle &circle)
{
    new ListNode (&head_, circle);
    ++size_;
}

void List::append(const Circle &circle)
{
    new ListNode (tail_.prev(), circle);
    ++size_;
}

void List::swap(List &other)
{
    head_.swap(other.head_);
    tail_.swap(other.tail_);
    std::swap(size_, other.size_);
}
