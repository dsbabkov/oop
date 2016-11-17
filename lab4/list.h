#include "listnode.h"
#include <utility>

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

    void swap(List &other);

    ListNode *begin() const;
    const ListNode *end() const;
    ListNode *rbegin() const;
    const ListNode *rend() const;

    bool removeFirst(const Circle &circle);
    size_t removeAll(const Circle &circle);

    void clear();
    bool isEmpty() const;
    size_t size() const;

    void sortBySquare() const;

private:
    void connecMiddleToEndings();
    void connectHeadToTail();

private:
    ListNode head_;
    ListNode tail_;

    size_t size_;
};

std::ostream &operator << (std::ostream &os, const List &list);
std::ifstream &operator >> (std::ifstream &is, List &list);
