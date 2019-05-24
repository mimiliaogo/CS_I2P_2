/* access range
[ begin_, last_)
[ begin_, end_)
*/
#include <iostream>
#include "11410_function.h"

using namespace std;
using namespace oj;
Vector::Vector() {
    begin_=nullptr;
    end_=nullptr;
    last_=nullptr;
}
size_t Vector::capacity() const
{
    return end_ - begin_;
}
size_t Vector::size() const
{
    return last_ - begin_;
}
void Vector::pop_back()
{
    if (size()>0) {
        last_--;
    }
}
void Vector::push_back(value_type val)
{
    if (end_==last_) {
        reserve(max(capacity()+1, 3*capacity()));
    }
    *(last_) = val;
    last_++;
}
Vector::~Vector()
{
    delete [] begin_;
    begin_ = last_ = end_ = nullptr;
}
void Vector::insert(size_type pos,size_type count,value_type val)
{
    if (capacity() < size() + count) {
        reserve(max(capacity()*3/2, capacity()+count));
    }
    std::copy_backward(begin_+pos, last_, last_+count);
    std::fill(begin_+pos, begin_+pos+count, val);
    last_+=count;
}

void Vector::reserve(size_type new_capacity)
{
    if (capacity()<new_capacity) {
        auto* start = new data_t[new_capacity];
        std::copy(begin_, last_, start);
        delete [] begin_;

        auto s = size();
        begin_ = start;
        last_ = begin_ + s;
        end_ = begin_ + new_capacity;
    }
}
void Vector::resize(size_type new_size)
{
    reserve(new_size);
    //if expand
    if (last_ < begin_ + new_size) {
        std::fill(last_, begin_+new_size, 0);
    }
    last_ = begin_ + new_size;
}
