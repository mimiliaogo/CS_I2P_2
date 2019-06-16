#include <iostream>
#include "function.h"
using namespace std;
using namespace oj;
void Vector::pop_back()
{
    if (size()>0) {
        last_--;
    }
}
void Vector::push_back(value_type val)
{
    if (size()>=capacity()) {
        reserve(max(capacity() + 1, capacity() * 3));
    }
    *(last_) = val;
    last_++;
}

void Vector::reserve(size_type new_capacity)
{

    if (new_capacity>capacity()) {
        auto* nv = new data_t[new_capacity];
        copy(begin_, last_, nv);
        auto s = size();
        last_ = nv + s;
        end_ = nv + new_capacity;
        delete [] begin_;
        begin_ = nv;
    }
}

Vector::~Vector()
{
    if (begin_) delete [] begin_;
    begin_=last_=end_ =nullptr;
}
