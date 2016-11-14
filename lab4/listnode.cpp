#include "listnode.h"

ListNode::ListNode()
    : prev_{}
    , next_{}
    , data_{}
{
}

ListNode::ListNode(ListNode *after, const Circle &circle)
    : prev_{after}
    , next_{}
    , data_{circle}
{
    if (!prev_){
        return;
    }

    next_ = prev_->next_;
    prev_->next_ = this;

    if (next_){
        next_->prev_ = this;
    }
}

ListNode::~ListNode()
{
    if (prev_){
        prev_->next_ = next_;
    }

    if (next_){
        next_->prev_ = prev_;
    }
}

Circle &ListNode::data()
{
    return data_;
}

const Circle &ListNode::data() const
{
    return data_;
}

ListNode *ListNode::prev() const
{
    return prev_;
}

ListNode *ListNode::next() const
{
    return next_;
}


