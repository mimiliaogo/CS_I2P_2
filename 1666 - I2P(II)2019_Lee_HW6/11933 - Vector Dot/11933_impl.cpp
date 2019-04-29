//
// Created by user on 4/27/2019.
//

#include <iostream>
#include "11933.h"
using namespace std;
// return the value of v[index]
const int Vector::operator[](int index) const
{
    return v[index];
}
// Dot product
int Vector::operator*(const Vector& a)
{
    int dot=0;
    int size = v_size;
    while (size!=0) {
        dot+=a.v[size-1]*this->v[size-1];
        size--;
    }
    return dot;
}
