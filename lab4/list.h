#include "listnode.h"

class List
{
public:
    List();
    List(const List &other);
    List(List &&other);
    ~List();

    List &operator = (const List &other);
    List &operator = (List &&other);

    void prepend(const Circle &circle);
    void append(const Circle &circle);

private:
    ListNode head_;
    ListNode tail_;

    size_t size_;
};
