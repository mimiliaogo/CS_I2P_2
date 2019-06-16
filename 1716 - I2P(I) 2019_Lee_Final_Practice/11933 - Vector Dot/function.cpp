#include <iostream>
#include "function.h"
using namespace std;
const int Vector::operator[](int index) const
{
    return v[index];
}
int Vector::operator*(const Vector& a)
{
    int dot=0;
    for (int i=0; i<v_size; i++) {
        dot+=v[i]*a.v[i];
    }
    return dot;
}
