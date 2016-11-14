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

}

List::List(List &&other)
{
}

List::~List()
{

}

List &List::operator =(const List &other)
{

}

List &List::operator =(List &&other)
{

}

void List::prepend(const Circle &circle)
{
    new ListNode (&head_, circle);
}

void List::append(const Circle &circle)
{
    new ListNode (tail_.prev(), circle);
}

