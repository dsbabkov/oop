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
    , size_{}
{
    head_.setNext(&tail_);

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
    clear();
}

List &List::operator =(const List &other)
{
    if (this == &other){
        return *this;
    }

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

    connecMiddleToEndings();
    other.connecMiddleToEndings();
}

ListNode *List::begin() const
{
    return head_.next();
}

const ListNode *List::end() const
{
    return &tail_;
}

ListNode *List::rbegin() const
{
    return tail_.prev();
}

const ListNode *List::rend() const
{
    return &head_;
}

bool List::removeFirst(const Circle &circle)
{
    for (ListNode *it = head_.next(); it != &tail_; it = it->next()){
        if (it->data() == circle){
            delete it;
            --size_;
            return true;
        }
    }
    return false;
}

size_t List::removeAll(const Circle &circle)
{
    size_t count = 0;

    for (ListNode *it = head_.next(); it != &tail_; it = it->next()){
        if (it->data() == circle){
            it = it->prev();
            delete it->next();
            ++count;
        }
    }

    size_ -= count;
    return count;
}

void List::clear()
{
    if (isEmpty()){
        return;
    }

    for (ListNode *p = head_.next(); p != &tail_; p = p->next(), delete p->prev());
    size_ = 0;
}

bool List::isEmpty() const
{
    return head_.next() == &tail_;
}

size_t List::size() const
{
    return size_;
}

void List::sortBySquare() const
{
    if (begin() == end()){
        return;
    }

    for (ListNode *p1 = begin(); p1 != tail_.prev(); p1 = p1->next()){
        double p1Square = p1->data().square();
        for (ListNode *p2 = p1->next(); p2 != &tail_; p2 = p2->next()){
            double p2Square = p2->data().square();
            if (p1Square > p2Square){
                p1->swapData(*p2);
                p1Square = p2Square;
            }
        }
    }
}

void List::connecMiddleToEndings()
{
    if (size_){
        head_.next()->setPrev(&head_);
        tail_.prev()->setNext(&tail_);
    }
    else{
        connectHeadToTail();
    }
}

void List::connectHeadToTail()
{
    head_.setNext(&tail_);
    tail_.setPrev(&head_);
}

std::ostream &operator <<(std::ostream &os, const List &list)
{
    for (ListNode *it = list.begin(); it != list.end(); it = it->next()){
        const Circle &circle = it->data();
        os << "Center: " << circle.center()
           << ", radius: " << circle.radius() << '\n';
    }
    return os;
}
