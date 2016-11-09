#include "oct.h"
#include <iostream>

void Oct::show() const
{
    std::cout << left_ << mid_ << right_ << '\n';
}
