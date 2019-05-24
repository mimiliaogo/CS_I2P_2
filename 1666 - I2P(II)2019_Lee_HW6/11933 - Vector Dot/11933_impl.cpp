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
    for (int i=0; i<v_size; i++) {
        dot+=v[i]*a.v[i];
    }
    return dot;
}
